#include "init.hpp"
#include "spin_matrix.hpp"
#include "metropolis.hpp"
#include "print.hpp"

#include <chrono>


int main()
{
  //set timer
  auto t1 = std::chrono::high_resolution_clock::now();

  //parameters
  int L = 20; //matrix length
  int N = L*L; //matrix size
  double T_0 = 1; // J/k. Initial temperature
  double T_end = 2.4; //J/k Final temperature
  int n = 10; //Temperature steps
  double delta_T = (T_end - T_0)/n;
  int burn_in = 1000; //burn in time 1000
  int mcc = 2500; //Monte Carlo cycles after burn in time

  // Construct a Mersenne Twister 19937 random number generator
  std::mt19937 generator;

  // Seed generator with thread number
  int seed = 2181;
  generator.seed(seed);

  //want ordered spin?
  int order = false;

  // Set a filename
  std::string filename = "test.txt";
  //open stream
  std::ofstream ofile;
  ofile.open(filename);


  for (int Ti = 0 ; Ti <= n; Ti++)
  {
    double T = T_0 + delta_T*Ti;

    //container for averages and Boltzmann factor
    arma::vec BF = arma::vec(17);
    arma::vec average = arma::vec(4,arma::fill::zeros);
    std::cout << T << std::endl;
    // setup array for possible energy changes (Idea by Morten)
    for( int i =-8; i <= 8; i++)
    {
      BF(i+8) = 0;
    }
    for( int i =-8; i <= 8; i+=4)
    {
      BF(i+8) = exp(-i/T);
    }

    //initialize energy and magnetization
    double E = 0;
    double M = 0;

    //initialize spin matrix
    arma::mat SM = spin_matrix(generator,L,order);

    //initial E and M
    init(SM,L,E,M);


    // burn in time
    for (int i = 1; i <= burn_in; i++)
    {
      Metropolis(L,generator, SM, E, M, BF);
    }


    #ifdef _OPENMP
    {
      //decide number of threads
      int num_threads = 4; //4 was the optimal
      omp_set_num_threads(num_threads);

      //parallel region
      #pragma omp parallel
      {
        // Seed generator with thread number
        int id = omp_get_thread_num();
        int extra_seed = 2180;
        generator.seed(id+10);

        //local E, M and spin matrix for each thread. Maybe a pointer is better
        double E_para = E;
        double M_para = M;
        arma::mat SM_para = SM;

        // sampling
        for (int i = 1; i <= mcc; i++)
        {

          Metropolis(L,generator, SM_para, E_para, M_para, BF);
          // update expectation values
          average(0) += E_para;
          average(1) += E_para*E_para;
          average(2) += fabs(M_para);
          average(3) += M_para*M_para;

        }
      }
      //get contribution from each thread and divide by number of threads to get average
      average = average/num_threads;
    }

    #else
    {
      // sampling
      for (int i = 1; i <= mcc; i++)
      {
        Metropolis(L,generator, SM, E, M, BF);
        // update expectation values
        average(0) += E;
        average(1) += E*E;
        average(2) += fabs(M);
        average(3) += M*M;
      }
    }


  #endif

  //print to file
  print(average,T,N,mcc,filename);

  //end of Temp loop
  }


  // Close the output file
  ofile.close();

  //stop timer
  auto t2 = std::chrono::high_resolution_clock::now();
  //calculate time
  double time = std::chrono::duration<double>(t2 - t1).count();
  std::cout << time << std::endl;

  return 0;
}
