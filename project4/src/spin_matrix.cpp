#include "spin_matrix.hpp"

//Initialize spin matrix
arma::mat spin_matrix(std::mt19937& generator,int L,int order)
{

  // generate "coinflip" distribution
  std::bernoulli_distribution pdf(0.5);
  //seed generator
  //std::mt19937 generator(seed);

  arma::mat spin_matrix = arma::mat(L,L);

  if (order == true)
  {
    for (int i = 0; i < L ; i++)
    {
      for (int j = 0 ; j  < L ; j++)
      {
        spin_matrix(i,j) = 1;
      }
    }
  }

  if (order == false)
  {
    for (int i = 0; i < L ; i++)
    {
      for (int j = 0 ; j  < L ; j++)
      {
        if (pdf(generator) == 0)
        {
          spin_matrix(i,j) = 1;
        }
        else
        {
          spin_matrix(i,j) = -1;
        }

      }
    }
  }

  return spin_matrix;
}
