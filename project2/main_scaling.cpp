#include "jacobi.hpp"
#include "max.hpp"
#include "tridiag.hpp"
#include "analytical.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>


//program that counts how many iterations
int main()
{

  // Parameters for output formatting
  int width = 18;
  int prec  = 10;


  //make matrix
  double n = 100; //changing this value for 5,10,20,...
  double h = 1/n;
  double a = -1*(1/(h*h));
  double d = 2*(1/(h*h));
  double e = -1*(1/(h*h));
  arma::mat A = create_tridiagonal(n,a,d,e);

  //create matrix R_0
  arma::mat R = arma::mat(n, n, arma::fill::eye);

  //get number of iterations from jacobi function
  double iterations = Jacobi(A, R);

  //print n and number of iterations
  std::cout << n << std::setw(width) << iterations << std::endl;






  return 0;
}
