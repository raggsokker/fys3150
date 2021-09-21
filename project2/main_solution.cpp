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


//program that prints out the solutions v_i's for both analytical and Jacobi
int main()
{

  // Parameters for output formatting
  int width = 18;
  int prec  = 10;


  //make matrix
  double N = 99; //N = n-1
  double h = 1/N;
  double a = -1*(1/(h*h));
  double d = 2*(1/(h*h));
  double e = -1*(1/(h*h));
  arma::mat A = create_tridiagonal(N,a,d,e);

  //create matrix R_0
  arma::mat R = arma::mat(N, N, arma::fill::eye);

  //Get D and R matrix. matrix D containing the eigenvalues is now called A. corresponding eigenvectors are matrix R
  double iterations = Jacobi(A, R);

  //find 3 lowest values corresponding to indices
  arma::vec eigenvalues_jacobi = arma::vec(N);
  for (int i = 0; i < N; i++)
  {
    eigenvalues_jacobi(i) = A(i,i);
  }

  //std::cout << sort_index(eigenvalues_jacobi);  //23, 75 and 47 (by manually checking) didnt find a better way, hehe

  //get the analytical eigenvalues and eigenvectors (these are already sorted)
  arma::mat ana_vec = eigenvectors(N);

  //print
  //add header
  std::cout << "#" << std::setw(30) << "Jacobi"
            << std::setw(55) << "analytical"
            << std::endl;

  for (int i = 0; i < N; i++)
  {
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << R(i,23)
              << std::setw(width) << std::setprecision(prec) << std::scientific << R(i,75)
              << std::setw(width) << std::setprecision(prec) << std::scientific << R(i,47)
              << std::setw(width) << std::setprecision(prec) << std::scientific << ana_vec(i,0)
              << std::setw(width) << std::setprecision(prec) << std::scientific << ana_vec(i,1)
              << std::setw(width) << std::setprecision(prec) << std::scientific << ana_vec(i,2)
              << std::endl;
  }

  return 0;
}
