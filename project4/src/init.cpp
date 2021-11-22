#include "init.hpp"


//calculate initial M and E
void init(arma::mat Matrix,int L, double& E, double& M)
{

  //calculate Energi E

  //All of matrix except upper and left side and boundary condition
  for (int j = 1; j < L ; j++)
  {
    for (int i = 1; i < L; i++)
    {
      E -= Matrix(i,j)*Matrix(i-1,j) + Matrix(i,j)*Matrix(i,j-1);
    }
  }

  //Upper and left side
  for (int i = 0 ; i < L-1 ; i++)
  {
    E -= Matrix(i,0)*Matrix(i+1,0) + Matrix(0,i)*Matrix(0,i+1);
  }

  //boundary
  for (int i = 0 ; i < L ; i++)
  {
    E -= Matrix(0,i)*Matrix(L-1,i) + Matrix(i,0)*Matrix(i,L-1);
  }


  //calculate magnetization M

  for (int i = 0 ; i < L ; i++)
  {
    for (int j = 0 ; j < L ; j++)
    {
      M += Matrix(i,j);
    }
  }


}
