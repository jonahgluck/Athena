#ifndef LINALG_h
#define LINALG_h

#include "TensorImpl.h"

namespace la {
  template<typename T, int n, int m>
    TensorImpl<T, m, n> T_(TensorImpl<T, n, m> t) {
      /*
       * 2D tranpose
       * Args:
       *  - t: A tensor of type TensorImpl with 
       *  dimensions n x m or n x n
       */
      TensorImpl<T, m, n> transposed; 
      for(std::size_t i=0; i<t.getDim()[0]; i++) {
        for(std::size_t j=0; j<t.getDim()[1]; j++) {
          transposed.get(j).update(i, t.get(i).get(j));
        }
      }
      return transposed;
    }
  //void permute() {}
  // permute
  // dot product
  // addition 
  // subtraction 
  // tensor prodcut ?
};

#endif
