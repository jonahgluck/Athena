#include <vector>
#include <cassert>

std::vector<std::vector<double>> MatMul2D(
    std::vector<std::vector<double>> &m1, 
    std::vector<std::vector<double>> &m2) {
  assert(m1[0].size() == m2.size() && "m1 cols does not match m2 rows");
  std::vector<std::vector<double>> product; 
  for(std::size_t row; row < m1.size(); row++) {
    for(std::size_t col; col < m1[0].size(); col++) {
      for(size_t inner; inner<m1.size(); inner++) {
        product[row][col] += m1[row][inner] * m2[inner][col];
      }
    }
  }

  return product;
};

