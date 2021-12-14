#include "initAB.hpp"


using namespace std::complex_literals;

//index converter
int idx(int i, int j,int L)
{
  int k = L*j + i;
  return k;
}

//initialize matrix A and B
void initAB(arma::sp_cx_mat& A, arma::sp_cx_mat& B,int M, double h, double dt, arma::sp_cx_mat V)
{
  //compute r
  std::complex<double> r = 1.0i*dt/(2.0*h*h);

  int L = (M-2)*(M-2);

  //Filling A and B with the Crank-Nicolson approach. We do this by making submatrices (diag and subdiag), which we later put into
  // A and B

  //diagonal submatrices
  arma::cx_mat diag = arma::cx_mat(M-2,M-2);
  arma::cx_mat subdiag = arma::cx_mat(M-2,M-2);

  //fill the diags
  for (int i = 0; i < M-3; i++)
  {
    diag(i,i+1) = r;
    diag(i+1,i) = r;
  }

  for (int i = 0; i < M-2; i++)
  {
    subdiag(i,i) = r;
  }

  //fill A and B with the diagonal and subdiagonal submatrices

  //Diagonal of A and B
  for (int i = 0; i < L; i+= M-2)
  {
    A.submat(i,i,i+M-3,i+M-3) -= diag;
    B.submat(i,i,i+M-3,i+M-3) += diag;
  }

  //A and B subdiag
  for (int i = 0; i < L-(M-2); i+= M-2)
  {
    A.submat(M-2+i,i,2*(M-2)-1 + i,M-3 + i) -= subdiag;
    B.submat(M-2+i,i,2*(M-2)-1 + i,M-3 + i) += subdiag;
  }

  //A and B superdiag
  for (int i = 0; i < L-(M-2); i+= M-2)
  {
    A.submat(i,M-2+i,M-3+i,2*(M-2)-1+i) -= subdiag;
    B.submat(i,M-2+i,M-3+i,2*(M-2)-1+i) += subdiag;
  }


  //create vectors a and b for diagonal of A and B
  arma::cx_vec a = arma::cx_vec(L);
  arma::cx_vec b = arma::cx_vec(L);

  for (int i = 0; i < M-2; i++)
  {
    for (int j = 0; j < M-2 ; j++)
    {
      int k = idx(j,i,M-2);
      std::complex<double> vji = V(j,i);
      a(k) = 1.0 + 4.0*r + 1.0i*dt/2.0*vji;
      b(k) = 1.0 - 4.0*r - 1.0i*dt/2.0*vji;
    }
  }


  //fill main diagonal of A and B with vectors a and b. Probably a more elegant way of doing this
  arma::sp_cx_mat a_mat = arma::sp_cx_mat(L,L);
  arma::sp_cx_mat b_mat = arma::sp_cx_mat(L,L);
  for (int i = 0; i < L; i+= 1)
  {
    a_mat(i,i) = a(i);
    b_mat(i,i) = b(i);
  }
  A += a_mat;
  B += b_mat;


}
