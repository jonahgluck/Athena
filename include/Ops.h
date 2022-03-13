#ifndef OPS_h
#define OPS_h

#include <initializer_list>

namespace ops {
  template<typename T>
  void fill(auto& t, auto dim, int val) {
    std::array<int, dim.size()> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        t.update(i, val);
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        fill<T>(t.get(i), new_dim, val);
      }
    }
  }
  template<typename T>
  void fill(auto& t, int val) {
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    // TODO: add condition if only 1 order tensor 
    for(std::size_t i=0; i<dim[0]; i++) {
      fill<T>(t.get(i), new_dim, val);
    }
  }
};

#endif
