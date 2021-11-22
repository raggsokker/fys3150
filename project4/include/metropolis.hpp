#ifndef __metropolis_hpp__
#define __metropolis_hpp__

#include <armadillo>
#include <iostream>
#include <math.h>
#include <random>

//this is more or less copy paste from compendium by Morten, same goes for metropolis function
inline int periodic(int i, int limit, int add);

void Metropolis(int L, std::mt19937& generator, arma::mat& spin_matrix, double& E, double&M, arma::vec Boltzmann);





#endif
