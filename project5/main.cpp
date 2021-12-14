#include <iostream>

#include "initAB.hpp"
#include "init_V.hpp"
#include "init_state.hpp"

int main()
{
  //parameters
  //step sizes and matrix size
  double h = 0.005;
  int M = 1/h;
  int L = (M-2)*(M-2);
  double dt = 2.5e-5;
  double T = 0.002;
  int N_t = 5;//T/dt;//T/dt;
  //potential strenght
  double v0 = 1e+10;
  //Gaussian wave parameters
  double x_c = 0.25;
  double y_c = 0.5;
  double sigma_x = 0.05;
  double sigma_y = 0.2;
  double p_x = 200;
  double p_y = 0;

  //set up A and B matrices
  arma::sp_cx_mat A = arma::sp_cx_mat(L,L);
  arma::sp_cx_mat B = arma::sp_cx_mat(L,L);

  //initialize V
  arma::sp_cx_mat V = arma::sp_cx_mat(M-2,M-2);
  //update V
  init_V(V,h,M, v0);

  //update A and B
  initAB(A,B,M,h,dt,V);

  //set up initial states
  arma::cx_cube U = arma::cx_cube(M,M,N_t);

  //update state
  init_state(U.slice(0),h,M,x_c,y_c,sigma_x, sigma_y, p_x, p_y);

  //solve for the next time step
  for (int i = 0; i < N_t-1  ; i++)
  {
    //convert slice of cube U to a vector of length M*M
    arma::cx_mat Usub = U.subcube( 1, 1, i, M-2, M-2, i );
    arma::cx_vec U_vec = Usub.as_col();

    //solve for next timestep
    arma::cx_vec b = B*U_vec;
    arma::cx_vec u_new = spsolve(A,b);

    //convert back to matrix again
    arma::cx_mat dum = arma::cx_mat(M,M);
    int idx = 0; //idx
    for (int j = 1; j < M-1; j++)
    {
      for (int k = 1; k < M-1; k++)
      {
        dum(k,j) = u_new(idx);
        idx += 1;
      }
    }
    //Make sure boundary wavefunction is zero
    for (int g = 0; g < M ; g++)
    {
      dum(g,0) = 0;
      dum(0,g) = 0;
      dum(M-1,g) = 0;
      dum(g,M-1) = 0;
    }
    //add to U cube
    U.slice(i+1) = dum;


  }

  //U.save("what.bin");

  return 0;
}
