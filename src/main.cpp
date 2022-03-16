#include "athena.h"
#include <iostream>

int main() {
  TensorImpl<double,4,3,5> x;
  //TensorImpl<double, 4> y;
  //op::fill<double>(x, 3);
  //op::tpow<double>(x, 3);

  std::cout << x.dtype() << std::endl;
  //op::fill<double>(y, 2);
  //x.get(0).get(0).update(1, 4)
  
  //int val = 1;
  //for(std::size_t i=0; i<x.getDim()[0]; i++) {
  //  for(std::size_t j=0; j<x.getDim()[1]; j++) {
  //    x.get(i).update(j, val);
  //    val += 1;
  //  }
  //}
  //
  //// 2d rect tensor transpoed 
  //auto nx = la::T_<double,3,3>(x);

  //for(std::size_t i=0; i<nx.getDim()[0]; i++) {
  //  for(std::size_t j=0; j<nx.getDim()[1]; j++) {
  //    std::cout << nx.get(i).get(j) << std::endl;
  //  }
  //}

  //for(int i=0; i<x.getDim()[0]; i++) {
  //  std::cout << x.get(i) << std::endl;
  //}

  //op::sq<double>(x);
  //op::tsqrt<double>(x);

  //for(int i=0; i<x.getDim()[0]; i++) {
  //  std::cout << x.get(i) << std::endl;
  //}

  return 0;
}

