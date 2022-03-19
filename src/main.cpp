#include "athena.h"
#include <iostream>

int main() {
  TensorImpl<double,3,4> x;
  //TensorImpl<double,4> y;

  //op::fill<double>(y, 2);
  op::fill<double>(x, 3);
  //auto s = la::sum(x, 1);
  //op::print<double>(s);
  //op::fill<double>(y, 5);
  //la::T_<double>(x);

  //auto res = la::matmul(x, y); // x:=3 and y:=5 -> X * Y = C where C:=45
  //op::randn<double>(x);
  
  //auto res = la::add<double>(x, y);
  
  // <T, N, M, I, O>
  //auto s = la::add(x, y);
  //op::print<double>(s);
  auto y = layers::Linear<double,3,4,4,3>().forward(x);
  auto res = layers::TanhActivation<double,3,3>().forward(y);
  op::print<double>(res);
  //op::tpow<double>(x, 3);

  //std::cout << x.dtype() << std::endl;
  //op::fill<double>(y, 2);
  //x.get(0).get(0).update(1, 4)
  
  //int val = 1;
  //for(std::size_t i=0; i<x.getDim()[0]; i++) {
  //  for(std::size_t j=0; j<y.getDim()[1]; j++) {
  //    std::cout << res.getDim()[0] << std::endl;
  //    std::cout << res.getDim()[1] << std::endl;
  //    std::cout << "val " << res.get(i).get(j) << std::endl;
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

