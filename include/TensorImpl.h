#ifndef TENSOR_IMPL_h
#define TENSOR_IMPL_h

#include <array>
#include <vector>
#include <cassert>
#include <initializer_list>
#include <iostream>

template <typename T, int m, int... N>
class TensorImpl {
  private:
    std::array<TensorImpl<T, N...>, m> tensor;
    std::array<int,sizeof...(N)+sizeof(m)> dim{m, N...};

  public:
    auto& get(std::size_t idx) {
      /*
       * return the value at an index
       */
      return tensor.at(idx);
    }

    std::array<int,sizeof...(N)+sizeof(m)> getDim() {
      /*
       * return the dimensions to the tensor
       */
      return dim;
    }

    int getLast() {
      return m;
    }
};

template <typename T, int m>
class TensorImpl<T, m> {
  // this is the last order of the recursive class above
  private:
    std::array<T, m> tensor;
  public:
    T& get(std::size_t idx) {
      /* 
       * return the value at an index
       */
      return tensor.at(idx);
    }

    void update(std::size_t idx, T value) {
      /* 
       * Update the value at in index
       */
      tensor.at(idx) = value;
    }

    std::array<int, 1> getDim() {
      /*
       * return the dimensions of the tensor
       */
      std::array<int, 1> dim = {m};
      return dim;
    }

    void item(int idx) {
      /* 
       * Print item at index
       */
      std::cout << tensor.at(idx) << std::endl;
    }
};
#endif
