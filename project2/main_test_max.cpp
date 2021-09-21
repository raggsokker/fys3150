#include "max.hpp"

int main()
{
  //make test matrix
  int n = 4;

  arma::mat A = arma::mat(n,n);

  A(0,0) = 1; A(1,0) = 0; A(2,0) = 0; A(3,0) = 0.5;
  A(0,1) = 0; A(1,1) = 1; A(2,1) = -0.7; A(3,1) = 0;
  A(0,2) = 0; A(1,2) = -0.7; A(2,2) = 1; A(3,2) = 0;
  A(0,3) = 0.5; A(1,3) = 0; A(2,3) = 0; A(3,3) = 1;
  //std::cout << A;

  //finding max element of test matrix
  int k = 0;
  int l = 0;
  double max = max_offdiag_symmetric(A, k, l);

  std::cout << "max =" << max << std::endl;
  std::cout << "k =" << k << std::endl;
  std::cout << "l =" << l << std::endl;



  return 0;
}
