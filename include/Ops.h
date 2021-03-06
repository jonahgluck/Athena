#ifndef OPS_h
#define OPS_h

#include <math.h> 
#include <cassert>
#include <ctime>

namespace op {
  template<typename T>
  void tpow(auto& t, auto dim, double power) {
    /*
     * A recursive function used to square every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     */
    std::array<int, dim.size()> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        t.update(i, pow(t.get(i), power));
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        tpow<T>(t.get(i), new_dim, power);
      }
    }
  }

  template<typename T, int N>
  void tpow(TensorImpl<T, N> &t, double power) {
    /*
     * A functoin to square a first order tensor.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      t.update(i, pow(t.get(i), power));
    }
  }

  template<typename T>
  void tpow(auto& t, double power) {
    /*
     * A recursive function used to square every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    for(std::size_t i=0; i<dim[0]; i++) {
      tpow<T>(t.get(i), new_dim, power);
    }
  }

  template<typename T, int N>
  void fill(TensorImpl<T, N> &t, int val) {
    /*
     * A functoin to fill a first order tensor.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     *  - val: a number to fill the tensor
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      t.update(i, val);
    }
  }
  
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
    std::array<int, dim.size()-1> new_dim;
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
    for(std::size_t i=0; i<dim[0]; i++) {
      fill<T>(t.get(i), new_dim, val);
    }
  }
  
  template<typename T, int N>
  void print(TensorImpl<T, N> &t) {
    /*
     * A functoin to fill a first order tensor.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     *  - val: a number to fill the tensor
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      std::cout << t.get(i) << std::endl;
    }
  }
  
  template<typename T>
  void print(auto& t, auto dim) {
    /*
     * A recursive function used to fill a given tensor with 
     * a desired number.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     *  - val: a number to fill the tensor
     */
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      // create a new array of indices without the first element 
      // which will be used to index the array 
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        std::cout << t.get(i) << std::endl;
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        print<T>(t.get(i), new_dim);
      }
    }
  }

  template<typename T>
  void print(auto& t) {
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
    for(std::size_t i=0; i<dim[0]; i++) {
      print<T>(t.get(i), new_dim);
    }
  }

  template<typename T, int N>
  void randn(TensorImpl<T, N> &t) {
    /*
     * A functoin to fill a first order tensor.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     *  - val: a number to fill the tensor
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      double frac = 1 / sqrt(2*M_PI);
      double rest = exp(-0.5 * pow(std::rand()%5,2));
      t.update(i, frac*rest);
    }
  }
  
  template<typename T>
  void randn(auto& t, auto dim) {
    /*
     * A recursive function used to fill a given tensor with 
     * a desired number.
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     *  - val: a number to fill the tensor
     */
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      // create a new array of indices without the first element 
      // which will be used to index the array 
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        double frac = 1 / sqrt(2*M_PI);
        double rest = exp(-0.5 * pow(std::rand()%5,2));
        t.update(i, frac*rest);
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        randn<T>(t.get(i), new_dim);
      }
    }
  }

  template<typename T>
  void randn(auto& t) {
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
    for(std::size_t i=0; i<dim[0]; i++) {
      randn<T>(t.get(i), new_dim);
    }
  }

  template<typename T>
  void ttanh(auto& t, auto dim) {
    /*
     * A recursive function used to take the sqrt of 
     * every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     */
    std::array<int, dim.size()> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        t.update(i, tanh(t.get(i)));
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        ttanh<T>(t.get(i), new_dim);
      }
    }
  }

  template<typename T, int N>
  void ttanh(TensorImpl<T, N> &t) {
    /*
     * A recursive function used to take the tanh of 
     * every value of a first order tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      t.update(i, tanh(t.get(i)));
    }
  }

  template<typename T>
  void ttanh(auto& t) {
    /*
     * A recursive function used to take tanh of 
     * every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    for(std::size_t i=0; i<dim[0]; i++) {
      ttanh<T>(t.get(i), new_dim);
    }
  }

  template<typename T>
  void ttanh_prime(auto& t, auto dim) {
    /*
     * A recursive function used to take the tanh of 
     * every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     */
    std::array<int, dim.size()> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        t.update(i, 1 - pow(tanh(t.get(i))));
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        ttanh_prime<T>(t.get(i), new_dim);
      }
    }
  }

  template<typename T, int N>
  void ttanh_prime(TensorImpl<T, N> &t) {
    /*
     * A recursive function used to take the sqrt of 
     * every value of a first order tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      t.update(i, 1 - pow(tanh(t.get(i))));
    }
  }

  template<typename T>
  void ttanh_prime(auto& t) {
    /*
     * A recursive function used to take the sqrt of 
     * every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    for(std::size_t i=0; i<dim[0]; i++) {
      ttanh_prime<T>(t.get(i), new_dim);
    }
  }
  template<typename T>
  void tsqrt(auto& t, auto dim) {
    /*
     * A recursive function used to take the sqrt of 
     * every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     *  - dim: dimensions of the tensor that can be accessed
     */
    std::array<int, dim.size()> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    if constexpr(sizeof(t.get(0)) == sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        t.update(i, sqrt(t.get(i)));
      }
      return;
    }
    else if constexpr(sizeof(t) != sizeof(T)) {
      for(std::size_t i=0; i<dim[0]; i++) {
        tsqrt<T>(t.get(i), new_dim);
      }
    }
  }

  template<typename T, int N>
  void tsqrt(TensorImpl<T, N> &t) {
    /*
     * A recursive function used to take the sqrt of 
     * every value of a first order tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl with an order of 1
     */
    std::array<int, sizeof(t.getDim())/sieof(t.getDim()[0])> dim = t.getDim();
    for(std::size_t i=0; i<dim[0]; i++) {
      t.update(i, sqrt(t.get(i)));
    }
  }

  template<typename T>
  void tsqrt(auto& t) {
    /*
     * A recursive function used to take the sqrt of 
     * every value of a tensor. 
     *
     * Args: 
     *  - t: A tensor of type TensorImpl
     */
    std::array<int, sizeof(t.getDim())/sizeof(t.getDim()[0])> dim = t.getDim();
    std::array<int, dim.size()-1> new_dim;
    for(std::size_t i=0; i<dim.size()-1; i++) {
      new_dim[i] = dim[i+1];
    }
    for(std::size_t i=0; i<dim[0]; i++) {
      tsqrt<T>(t.get(i), new_dim);
    }
  }
};

#endif
