#include "init_V.hpp"


//Computes the potential matrix V
void init_V(arma::sp_cx_mat& V, double h,int M, double v0)
{
  double dx = 0.02;
  double dy = 0.05;
  int Nx = dx/h;
  int Ny = dy/h;

  //make the walls

  for (int i = 0; i < M-2; i++)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = v0;
    }
  }

  //configuration for double slit.

  //make the holes
  //upper hole

  for (int i = (M-1)/2 + Ny/2; i < (M-1)/2 + 3*Ny/2; i++)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = 0;
    }
  }

  //lower hole
  for (int i = (M-1)/2 - Ny/2; i > (M-1)/2 - 3*Ny/2; i--)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = 0;
    }
  }


  //configuration for single slit.

  //single hole
  /*
  for (int i = (M-1)/2 - Ny/2; i < (M-1)/2 + Ny/2; i++)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = 0;
    }
  }
  */

  //configuration for triple slit.
  /*
  //middle hole
  for (int i = (M-1)/2 - Ny/2; i < (M-1)/2 + Ny/2; i++)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = 0;
    }
  }

  //upper hole
  for (int i = (M-1)/2 + 3*Ny/2; i < (M-1)/2 + 5*Ny/2; i++)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = 0;
    }
  }
  //upper hole
  for (int i = (M-1)/2 - 3*Ny/2; i > (M-1)/2 - 5*Ny/2; i--)
  {
    for (int j = (M-1)/2-Nx/2; j < (M-1)/2 +Nx/2; j++)
    {
      V(j,i) = 0;
    }
  }
  */


  //configuration for circular potential. Must comment out "make walls" when using this potential
  // will have same thickness on walls as for the slit potentials
  // with radius = 0.3
  /*
  double radi = 0.3;
  int Nr = radi/h;
  for (int r = Nr - Nx/2 ; r < Nr + Nx/2 ; r++)
  {
    for (int i = 0 ; i < M-2; i++)
    {
      for (int j = 0 ; j < M-2; j++)
      {
        double x = (j - (M-1)/2)*h;
        double y = (i - (M-1)/2)*h;
        double ri = r*h;
        if (fabs(sqrt(x*x + y*y) - ri) <= h)
        {
          V(j,i) = v0;
        }

      }
    }
  }
  */
  //potential as 2.5e+4 shows tunneling


}
