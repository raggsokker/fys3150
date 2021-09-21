#ifndef __max_hpp__
#define __max_hpp__

#include <armadillo>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>


double max_offdiag_symmetric(const arma::mat& A, int& k, int &l);

#endif
