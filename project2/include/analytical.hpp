#ifndef __analytical_hpp__
#define __analytical_hpp__

#include <armadillo>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

//computes eigenvalues. Stored in the vector
arma::vec eigenvalues(double a,double d, double n);

//computes eigenvectors. The eigenvectors are stores as columns in the matrix
arma::mat eigenvectors(double n);


#endif
