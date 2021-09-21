#include "jacobi.hpp"
#include "max.hpp"
#include "tridiag.hpp"
#include "analytical.hpp"


//program that makes use of the jabobi's method and compared it to the analytical
//If you run this program, you will see that the eigenvectors and eigenvalues are ordered differently
//comparing Jacobi's and the analytical. But ofc the vectors match the values
int main()
{
  //make matrix
  double n = 6;
  double h = 1/n;
  double a = -1*(1/(h*h));
  double d = 2*(1/(h*h));
  double e = -1*(1/(h*h));
  arma::mat A = create_tridiagonal(n,a,d,e);

  //create matrix R_0
  arma::mat R = arma::mat(n, n, arma::fill::eye);

  //get D and S matrix, which is A and R respectively
  double iterations = Jacobi(A, R);

  //print Jacobi's eigenvec and values
  std::cout << "Jacobi eigenvectors =" << std::endl;
  std::cout << R << std::endl;
  std::cout << "Jacobi's eigenvalues =" << std::endl;
  std::cout << A << std::endl;

  //get analytical eigenvec and values
  arma::mat ana_vecs = eigenvectors(n);
  arma::mat ana_vals = eigenvalues(a,d,n);

  //print analytical eigenvec and values
  std::cout << "ana vecs =" << std::endl;
  std::cout << ana_vecs << std::endl;
  std::cout << "ana eigs =" << std::endl;
  std::cout << ana_vals << std::endl;


  return 0;
}
