#ifndef __init_state_hpp__
#define __init_state_hpp__

#include <armadillo>


//Compute initial state u^0
void init_state(arma::cx_mat& U, double h,int M, double x_c, double y_c, double sigma_x, double sigma_y, double p_x, double p_y);
  /* updates the initial state u^0 and normalizes it*/


#endif
