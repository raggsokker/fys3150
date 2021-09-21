#include "tridiag.hpp"

arma::mat create_tridiagonal(int n, double a, double d, double e)
{
  // Start from identity matrix
  arma::mat A = arma::mat(n, n, arma::fill::eye);

  // Fill the first row
  A(0,0) = d;
  A(0,1) = e;

  // Loop that fills rows 2 to n-1 (row indices 1 to n-2)
  for (int i = 1; i <= n-2 ; i++)
  {
    A(i,i) = d;
    A(i,i-1) = a;
    A(i,i+1) = e;

  }
  // Fill last row (row index n-1)
  A(n-1,n-1) = d;
  A(n-1,n-2) = a;



  return A;
}
