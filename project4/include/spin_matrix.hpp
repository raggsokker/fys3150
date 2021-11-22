#ifndef __spin_matrix_hpp__
#define __spin_matrix_hpp__

#include <armadillo>
#include <iostream>
#include <math.h>
#include <random>

//Initialize spin matrix
arma::mat spin_matrix(std::mt19937& generator,int L,int order);




#endif
