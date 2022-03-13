#include "athena.h"
#include <iostream>

int main() {
  //Tensor<double*> x({2,2,2});
  //std::cout << "transpose: " << std::endl;
  //x.T<double>();
  //double d = x.get<double>({0,1,1});
  //std::cout << "selected value: " << d << std::endl;

  TensorImpl<double, 4,5,2> x;
  ops::fill<double>(x, 5);

  //x.get(0).get(0).update(1, 4)

  //for(std::size_t i=0; i<4; i++) {
    //for(std::size_t j=0; j<2; j++) {
      //for(std::size_t k=0; k<sizeof(x.get(0).get(0))/sizeof(x.get(0).get(0).get(0)); k++) {
        //std::cout << i << j << std::endl;
        //std::cout << x.get(i) << std::endl;
      //}
    //}
  //}
  
  return 0;
}

