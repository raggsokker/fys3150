#include "particle.hpp"
#include "penningtrap.hpp"



int main()
{

  //variables
  int n = 100; // # of particles

  double q = 2; //e
  double m = 40.078; //atomic mass
  double k_e = 1.39e5; // u*(mu m)^3/((mu s)^2*e^2)
  double k_tot = k_e*q*q/m; // (mu m)^3/(mu s)^2

  //trap parameters
  double f = 0.1;
  double B0 = 9.65e1; // u/(mu s*e)
  double V0 = 2.41e5; // u*(mu m)^2/((mu s)^2*e)
  double d = 500; // mu m

  //step and runtime
  double b = 500; //mu sec
  double dt = 0.01; //mu sec
  double N = b/dt;

  int exchange = true; //toggle exchange force

  //Initialize time array
  arma::vec t = arma::vec(N);
  //start condition
  t(0) = 0;

  //omega_V steps and intervals
  double omega_V_0 = 0.45; //MHz
  double omega_V_end = 0.87; //MHz
  double omega_interval = omega_V_end - omega_V_0;
  double delta_omega = 0.002; //MHz stepsize
  int n_omega = omega_interval/delta_omega;

  arma::vec P = arma::vec(n_omega); //particle container for different choices of omega_V
  arma::vec omega_V = arma::linspace(omega_V_0,omega_V_end,n_omega);
  std::cout << P.size() << std::endl;
  std::cout << omega_V.size() << std::endl;


  for (int k = 0; k < n_omega; k ++)
  {
    //create trap
    penningtrap my_trap(B0,V0,d,f,omega_V(k));
    //add n particles
    for (int i=0; i < n; i++)
      {
        //assign random values for velocity and position
        arma::vec r = arma::vec(3).randn() * 0.1 * d;  // random initial position
        arma::vec v = arma::vec(3).randn() * 0.1 * d;  // random initial velocity

        //add to trap
        my_trap.add_particle(q,m,v,r);
      }

    for (int i = 1 ; i < N ; i++)
    {
      //update time
      t(i) = dt*i;
      //evolve system
      my_trap.evolve_RK4(k_tot, dt, exchange, t(i));

      for (int j = 0 ; j < n ; j++)
      {
        //extract new r
        arma::vec r_new = my_trap.get_r(j);
        //remove particle from trap if r > d
        if (arma::norm(r_new) > d && my_trap.particle_count() != 0)
        {
          my_trap.remove(j);
        }
      }
    }

    P(k) = my_trap.particle_count();
  }




  P.save("P_f1.bin");
  omega_V.save("omega_V.bin");


  return 0;
}
