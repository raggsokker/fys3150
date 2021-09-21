#include "jacobi.hpp"
#include "max.hpp"

//function that implements Jacobi's algo. Returns the number of iterations and changes the
//references A and R to D and S. Where D is the matrix containing the eigenvalues
//and S is the matrix containing the eigenvectors

//NOTE! I had A LOT of buggs that I struggled with the first time I ran this function. Ended
// up taking a lot of inspiration from the compendium by Morten.
double Jacobi(arma::mat& A, arma::mat& R)
{

  int iterations = 0;
  //find first max value with indices
  int k;
  int l;
  double max = max_offdiag_symmetric(A,k,l); //we never use max variable. but the function updates k and l

  //find dim of A and define lower toleranse for epsilon
  int n = A.n_rows;
  double eps = 1.0e-8;

  //Jacobis method
  while (fabs(A(k,l)) > eps)
  {
    //calculate tan, cos and sin
    double t; double c ; double s; double tau;

    if (A(k,l) != 0)
    {
      tau = (A(l,l)-A(k,k))/(2*A(k,l));
      if (tau > 0)
      {
        t = 1/(tau + sqrt(1+tau*tau));
      }
      else
      {
        t = -1/(-tau + sqrt(1+tau*tau));
      }
      c = 1/(sqrt(1+t*t));
      s = c*t;
    }
    else
    {
      c = 1;
      s = 0;
      t = 0;
    }

    //transform A
    double a_kk = A(k,k);
    double a_ll = A(l,l);

    A(k,k) = a_kk*c*c - 2*A(k,l)*c*s + a_ll*s*s;
    A(l,l) = a_ll*c*c + 2*A(k,l)*c*s + a_kk*s*s;
    A(k,l) = 0;
    A(l,k) = 0;

    //update the rest with for loop
    for (int i = 0; i < n; i++)
    {
      if (i != k && i != l)
      {
        double a_ik = A(i,k);
        double a_il = A(i,l);

        A(i,k) = a_ik*c - a_il*s;
        A(k,i) = A(i,k);
        A(i,l) = a_il*c + a_ik*s;
        A(l,i) = A(i,l);
      }
    }
    //update for R
    for (int i = 0; i < n; i++)
    {
      double r_ik = R(i,k);
      double r_il = R(i,l);

      R(i,k) = r_ik*c - r_il*s;
      R(i,l) = r_il*c + r_ik*s;
    }

    //find new max off-diag with new indices
    double new_max = max_offdiag_symmetric(A,k,l); //we never use max variable, but the indices l and k, get updated
    iterations ++;

  }
  return iterations;
}
