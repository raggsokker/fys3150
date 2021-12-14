#include "init_state.hpp"

using namespace std::complex_literals;

//Compute initial state u^0
void init_state(arma::cx_mat& U, double h,int M, double x_c, double y_c, double sigma_x, double sigma_y, double p_x, double p_y)
{
  for (int i = 1; i < M-1; i++)
  {
    for (int j = 1; j < M-1; j++)
    {
      double xi = j*h;
      double yi = i*h;
      U(j,i) = exp(-pow(xi-x_c,2.0)/(2.0*sigma_x*sigma_x) -pow(yi-y_c,2.0)/(2.0*sigma_y*sigma_y) + 1.0i*p_x*(xi-x_c) + 1.0i*p_y*(yi-y_c));
    }
  }

  //normalize
  std::complex<double> s = 0;
  for (int i = 1; i < M-1; i++)
  {
    for (int j = 1; j < M-1; j++)
    {
      s += conj(U(j,i))*U(j,i);
    }
  }
  std::complex<double> A = sqrt(1.0/s);
  U = A*U;


}
