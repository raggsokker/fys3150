#ifndef __initAB_hpp__
#define __initAB_hpp__

#include <armadillo>

//index converter
int idx(int i, int j, int L);

//initializes matrix A and B
void initAB(arma::sp_cx_mat& A, arma::sp_cx_mat& B,int M, double h, double dt, arma::sp_cx_mat V);


#endif
