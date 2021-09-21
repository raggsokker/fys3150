#include "analytical.hpp"

//function for eigenvectors
arma::mat eigenvectors(double n)
{
  // Start from identity matrix
  arma::mat eigenvectors = arma::mat(n, n, arma::fill::eye);

  // Loop that fills matrix with the eigenvectors
  for (int i = 0; i <= n-1 ; i++)
  {
    for (int j = 0; j <= n-1 ; j++)
    {
      eigenvectors(j,i) = sin((i+1)*(j+1)*M_PI/(n+1));
    }
  }
  //normalise the vector
  arma::mat norm = arma::normalise(eigenvectors);
  return norm;
}




//function for eigenvalues
arma::vec eigenvalues(double a, double d, double n)
{
  //initialize empty column vector
  arma::vec eigenvalues = arma::vec(n);

  // Loop that fills vector with the eigenvalues
  for (int i = 0; i <= n-1 ; i++)
  {
    eigenvalues(i) = d + 2*a*cos((i+1)*M_PI/(n+1));

  }
  return eigenvalues;
}
