#include "max.hpp"
//function to find max abs value in the off-diagonal of a symmetric matrix
//NOTE! This function is copy-paste from the compendium by Morten
double max_offdiag_symmetric(const arma::mat& A, int& k, int &l)
{
  int n = A.n_rows;
  double max = 0.0;
  for ( int i = 0; i < n; i++ ) {
    for ( int j = i + 1; j < n; j++ ) {
      if ( fabs(A(i,j)) > max ) {
  max = fabs(A(i,j));
  l = i;
  k = j;
      }
    }
  }
  return max;
}
