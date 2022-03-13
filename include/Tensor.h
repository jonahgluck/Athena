#ifndef TENSOR_h
#define TENSOR_h

#include <cstddef>
#include <iostream>
#include <cassert>
#include <vector>
#include <initializer_list>

template<typename T_>
class Tensor {
  private:
    T_ tensor{nullptr};
    int scalar_; 
    std::vector<int> dims;
    int linear_size;

  public:
    Tensor(const std::initializer_list<int> &d) : dims(d) {
      /*  Tensor class constructor 
       *    Tensor<dataType*> x(I, J, K, N, ...)
       *  
       *  Return an element at an index
       *    - get()
       *  Transpose 
       *    - T()
       *  Return dimensions of tensor
       *    - dim()
       */

      int scalar = 1; 
      for(int e : d) {
        scalar *= e;
      }
      
      scalar_ = scalar;

       tensor = (T_) malloc(sizeof *tensor * scalar);
       linear_size = scalar;

      if(tensor == NULL) {
        std::cout << "Could not allocate tensor" << std::endl;
      }
      else { 
      // fill arr with testing values - TODO: Make this random initialization 
        for(int i=0; i<scalar_; i++) {
          tensor[i] = i;
          std::cout << tensor[i] << std::endl;
        }
      }
    };

    ~Tensor() {
      free(tensor);
    };

    template<typename TT>
    void T() {
      /*  Tranpose tensor  */

      std::vector<TT> temp; 

      // square matrix transpose 
      if (dims.size() == 2 && dims[0]==dims[1]) {
        for(std::size_t i=0; i<linear_size; i++) {
          for(std::size_t j=i; j<linear_size; j+=dims[dims.size()-1]) {
            temp.push_back(tensor[j]);
          }
        }

        for(std::size_t i=0; i<linear_size; i++) {
          tensor[i] = temp[i];
        }

        for(std::size_t i=0; i < linear_size; i++) {
          std::cout << tensor[i] << std::endl;
        }
      }
      else {
        for(std::size_t i=0; i<linear_size; i++) {
          for(std::size_t j=i; j<linear_size; j+=dims[dims.size()-1]) {
            temp.push_back(tensor[j]);
          }
        }

        for(std::size_t i=0; i<linear_size; i++) {
          tensor[i] = temp[i];
        }

        for(std::size_t i=0; i < linear_size; i++) {
          std::cout << tensor[i] << std::endl;
        }
      }
    }

    std::vector<int> dim() {
      /*  Return the dimensions of the tensor that was initialized  */
      return this->dims;
    }

    template<typename TT>
    TT get(const std::initializer_list<int> &idxs) {
      /*  Return a value from a specified index in the initializer list
       *    
       *  Tensor<dataType*> x(I, J, K, N, ...);
       *  x.get({I-1, J-1, K-1, N-1, ...});
       *
       *  indexing is linear so instead of 
       *  a[x][y][z] == a_scalar[x * size_y * size_z + y * size_z + z]
       *  each temporary (input) dimension is multiplied by the length of the 
       *  corresponding dimensions below its dimension and then these values are added
       */

      std::vector<int> temp(idxs.begin(), idxs.end());
    
      for(std::size_t i=0; i < temp.size(); i++) {
        if(temp[i] >= dims[i]) {
          std::cout << "Error at dim " << i << "." << std::endl;
        }
        assert(temp[i] < dims[i] && "get(): Dimensions specified is larger than allocated.");
      }
 
      int factor = 1;
      int sum = 0; 
      int scalar = 0;
      for(std::size_t i=0; i < temp.size()-1; i++) {
        sum = temp[i];
        for(std::size_t j=i+1; j<dims.size(); j++) {
          factor *= dims[j];
        } 
        scalar += sum * factor;
        factor = 1;
      }
      scalar += temp[temp.size()-1];
      
      return tensor[scalar];
    }
};

#endif
