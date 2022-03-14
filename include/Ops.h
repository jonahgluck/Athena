#ifndef OPS_h
#define OPS_h

namespace ops {
  template<typename T>
  void fill(auto& t, auto dim, int val) {
    /*
     * A recursive function used to fill a given tensor with 
     * a desired number.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     *  - val: a number to fill the tensor
     */
    std::array<int, dim.size()> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      // create a new array of indices without the first element 
      // which will be used to index the array 
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
    /*
     * A recursive function used to fill a given tensor with 
     * a desired number.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - val: a number to fill the tensor
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    // TODO: add condition if only 1 order tensor using check for TensorImpl<T, N>
    for(std::size_t i=0; i<dim[0]; i++) {
      fill<T>(t.get(i), new_dim, val);
    }
  }
};

#endif
