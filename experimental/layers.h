#ifndef LAYERS_h
#define LAYERS_h

#include "Ops.h"
#include <math.h>
#include <functional>

namespace layers {
  template<typename T, int M, int N, int I, int O>
  class Linear {
    private:
      TensorImpl<T, I, O> weights;
      TensorImpl<T, O> bias;
      std::string name = "linear";
      //TensorImpl<T, I, M> inputs; 

    public:
      Linear() {
        op::randn<T>(weights);
        op::randn<T>(bias);
      }

      // TODO: figure out what auto would be here for type checks
      auto forward(auto in) {
        /* 
         * out = in * w + b
         */
        // TODO: add assignment operator = 
        // inputs = in;
        
        TensorImpl<T, M, O> xw = la::matmul(in, weights);
        return la::add(xw, bias);
      }

      // TODO: figure out what auto would be here for type checks
      auto backward(auto in, auto grad) {
        auto b_grad = la::sum(grad, 0);
        auto w_grad= la::matmul(in.T_(), grad);
        return la::matmul(grad, la::matmul(in, weights).T_());
      }
  };

  template<typename TT, int TN, int TM>
  class TanhActivation {
    public:
      TanhActivation() {};

      auto forward(auto in) {
        op::ttanh<TT>(in);
        return in;
      }

      auto backward(auto in, auto grad) {
        op::ttanh_prime<TT>(in);
        return la::matmul(in, grad);
      }
  }; 
};

#endif 
