#ifndef TENSOR_IMPL_h
#define TENSOR_IMPL_h

#include <array>
#include <vector>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <utility>

template<typename T, int m, int... N>
class TensorImpl {
  private:
    std::array<TensorImpl<T, N...>, m> tensor;
    std::array<int,sizeof...(N)+sizeof(m)> dim{m, N...};

  public:
    auto& get(std::size_t idx) {
      /*
       * @return the value at an index
       */
      return tensor.at(idx);
    }

    constexpr std::array<int,sizeof...(N)+sizeof(m)> getDim() {
      /*
       * @return the dimensions to the tensor
       */
      return dim;
    }

    std::string dtype() {
      /* 
       * @return dataType of items stored in the tensor
       * its associated with.
       */
      if(sizeof(T) == sizeof(double)) {
        return "double";
      } 
      else if(sizeof(T) == sizeof(int)) {
        return "int";
      } 
      else if(sizeof(T) == sizeof(long double)) {
        return "long double";
      }
      else if(sizeof(T) == sizeof(long int)) {
        return "long int";
      }
      else if(sizeof(T) == sizeof(short int)) {
        return "short int";
      }
      else if(sizeof(T) == sizeof(float)) {
        return "long int";
      }
      else if(sizeof(T) == sizeof(unsigned char)) {
        return "unsigned char";
      }
      return "unknown";
    }
};

template<typename T, int m>
class TensorImpl<T, m> {
  // this is the last order of the recursive class above
  private:
    std::array<T, m> tensor;
  public:
    T& get(std::size_t idx) {
      /* 
       * @return the value at an index
       */
      return tensor.at(idx);
    }

    void update(std::size_t idx, T value) {
      /* 
       * Update the value at in index
       */
      tensor.at(idx) = value;
    }

    constexpr std::array<int, 1> getDim() {
      /*
       * @return the dimensions of the tensor
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

    std::string dtype() {
      /* 
       * @return dataType of items stored in the tensor
       * its associated with.
       */
      if(sizeof(T) == sizeof(double)) {
        return "double";
      } 
      else if(sizeof(T) == sizeof(int)) {
        return "int";
      } 
      else if(sizeof(T) == sizeof(long double)) {
        return "long double";
      }
      else if(sizeof(T) == sizeof(long int)) {
        return "long int";
      }
      else if(sizeof(T) == sizeof(short int)) {
        return "short int";
      }
      else if(sizeof(T) == sizeof(float)) {
        return "long int";
      }
      else if(sizeof(T) == sizeof(unsigned char)) {
        return "unsigned char";
      }
      return "unknown";
    }
};

    // TODO: initialize from lists
    //void init(std::initializer_list<size_t> init_vals) {
    //  std::vector<std::size_t> v(init_vals.begin(), init_vals.end());
    //}
    //TensorImpl<T, m, N...>& operator= (std::initializer_list<int> il) {
    //  std::cout << "test";
    //  return this*;
    //}

#endif
