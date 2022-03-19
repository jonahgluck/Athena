#ifndef LINALG_h
#define LINALG_h

#include "TensorImpl.h"
#include <cassert>

namespace la {
  template<typename T, int n, int m>
  TensorImpl<T, m, n> T_(TensorImpl<T, n, m> t) {
    /*
     * @return a 2d tranpose of the original tensor
     * @param a tensor of type TensorImpl with dimensions n x m or n x n
     */
    auto dims = t.getDim();
    assert((dims.size() > 2 || dims.size() < 2 ) && "Transpose does not support currently support more or less than 2 dimensions");
    TensorImpl<T, m, n> transposed; 
    for(std::size_t i=0; i<t.getDim()[0]; i++) {
      for(std::size_t j=0; j<t.getDim()[1]; j++) {
        transposed.get(j).update(i, t.get(i).get(j));
      }
    }
    return transposed;
  }
  
  template<typename T, int N1, int M1, int N2, int M2>
  TensorImpl<T, N1, M2> matmul(TensorImpl<T, N1, M1> m1, TensorImpl<T, N2, M2> m2) {
    /*
     * @return a tensor of type TensorImpl and size N1 x M2 
     * @param m1: a tensor of type TensorImpl size N1 x M1
     * @param m2: a tensor of type TensorImpl size N2 x M2
     */
    assert(M1 == N2 && "Cannot multiply because M1 and N2 do not match");
    TensorImpl<T, N1, M2> res;
    for (int i = 0; i < N1; i++) {
      for (int j = 0; j < M1-1; j++) {
        int sum = 0;
        res.get(i).update(j, 0);
        for (int k = 0; k < M2; k++) {
          sum += m1.get(i).get(k) * m2.get(k).get(j);
        }
        res.get(i).update(j, sum);
      }
    }
    return res; 
  }

  template<typename T, int N1, int M1, int M>
  TensorImpl<T, N1, M1> add(TensorImpl<T, N1, M1> m1, TensorImpl<T, M> m2) {
    /*
     * @return a tensor that is the result of m1 + m2
     * @param m1: the larger tensor of N1 x M1 dimensions
     * @param m2: a 1 x M2 dimensional tensor
     */

    // TODO: allow different length columns and then use rows instead
    assert(N1 != 1 && "The first tensor cannot have a dimension of 1 as N");
    assert(m1.getDim()[1] == m2.getDim()[0] && 
        "M dimension of m1 cannot be added with the single dimension of m2");
    TensorImpl<T, N1, M1> res;
    for(int i=0; i<N1; i++) {
      for(int j=0; j<M1; j++) {
        res.get(i).update(j, m1.get(i).get(j) + m2.get(j));
      }
    }
    return res;
    }

  template<typename T, int N, int M>
  TensorImpl<T, M> sum(TensorImpl<T, N, M> t, int axis) {
    /*
     * @return the sum of the given axis 
     * @param t: A 2D tensor
     * @param axis: the direction to calculate the sum 
     *              (0: sum for each row || 1: sum for each col)
     */

    TensorImpl<T, M> res;
    if(axis == 0) {
      for(int i=0; i<N; i++) {
        int sum = 0;
        for(int j=0; j<M; j++) {
          sum += t.get(i).get(j);
        }
        res.update(i, sum);
      }
    }
    else {
      for(int i=0; i<M; i++) {
        int sum = 0;
        for(int j=0; j<N; j++) {
          sum += t.get(j).get(i);
        }
        res.update(i, sum);
      }
    }
    return res;
  }
};

#endif
