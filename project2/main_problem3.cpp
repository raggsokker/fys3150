#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include "tridiag.hpp"
#include "analytical.hpp"



int main()
{

  //variables
  double n = 6;
  double h = 1/n;
  double a = -1*(1/(h*h));
  double d = 2*(1/(h*h));
  double e = -1*(1/(h*h));

  //get our tridiagonal matrix
  arma::mat A = create_tridiagonal(n,a,d,e);

  //calculate eigenvalues and eigenvectors using armadillo
  arma::vec eigval;
  arma::mat eigvec;
  eig_sym(eigval,eigvec, A,"std");

  //analytical calculation of eigenvectors/values
  arma::vec ana_eigvals = eigenvalues(a,d,n);
  arma::mat ana_eigvecs = eigenvectors(n);


  //print result
  std::cout << "eigenvalues computated using armadillo" << std::endl;
  std::cout << eigval << std::endl;
  std::cout << "eigenvalues computated analytically" << std::endl;
  std::cout << ana_eigvals << std::endl;
  std::cout << "eigenvectors computated using armadillo" << std::endl;
  std::cout << eigvec << std::endl;
  std::cout << "eigenvectors computated analytically" << std::endl;
  std::cout << ana_eigvecs << std::endl;


  // Return 0 when done
  return 0;
}
