#include "metropolis.hpp"

// inline function for periodic boundary conditions
// As mentioned in hpp file. This is more or less copy paste from Morten
inline int periodic(int i, int L, int add)
{
  return (i+L+add) % (L);
}

//metropolis function
void Metropolis(int L, std::mt19937& generator, arma::mat& SM, double& E, double&M, arma::vec Boltzmann)
{
  //seed generator
  //std::mt19937 generator(seed);

  std::uniform_real_distribution<double> real_pdf(0,1);

  // loop over all spins
  for(int y =0; y < L; y++)
  {
      for (int x= 0; x < L; x++)
      {
          // Find random position
          int ix = real_pdf(generator)*(L);
          int iy = real_pdf(generator)*(L);

          //find change in energy
          int deltaE = 2*SM(iy,ix)*
          (SM(iy,periodic(ix,L,-1))+
          SM(periodic(iy,L,-1),ix) +
          SM(iy,periodic(ix,L,1)) +
          SM(periodic(iy,L,1),ix));
          // Here we perform the Metropolis test
          if ( real_pdf(generator) <= Boltzmann(deltaE+8) )
           {
            SM(iy,ix) *= -1; // flip one spin and accept new spin config

            // update energy and magnetization
            M += 2*SM(iy,ix);
            E += deltaE;
            }
      }
    }
}
