#include "particle.hpp"
#include "penningtrap.hpp"

int main()
{

  //variables
  int n = 2; // # of particles

  double q = 2; //e
  double m = 40.078; //atomic mass
  double k_e = 1.39e5; // u*(mu m)^3/((mu s)^2*e^2)
  double k_tot = k_e*q*q/m; // (mu m)^3/(mu s)^2

  double B0 = 9.65e1; // u/(mu s*e)
  double V0 = 9.65e8; // u*(mu m)^2/((mu s)^2*e)
  double d = 1e4; // mu m

  int exchange = false; //toggle exchange force

  penningtrap my_trap(B0,V0,d);

  //step and runtime
  double b = 100; //mu sec
  double dt = 0.001; //mu sec
  double N = b/dt;

  //Initialize position, velocity and time arrays
  arma::cube V = arma::cube(N, 3, n);
  arma::cube R = arma::cube(N, 3, n);
  arma::vec t = arma::vec(N);

  //add n particles
  arma::vec r1 = {150,150,150};
  arma::vec v1 = {100,100,100};
  arma::vec r2 = {100,100,100};
  arma::vec v2 = {100,100,100};

  //add to trap
  my_trap.add_particle(q,m,v1,r1);
  my_trap.add_particle(q,m,v2,r2);

  //Start position, velocity and time
  V.slice(0).row(0) = v1.t(); //had to transpose
  R.slice(0).row(0) = r1.t();

  V.slice(1).row(0) = v2.t();
  R.slice(1).row(0) = r2.t();

  t(0) = 0;



  for (int i = 1 ; i < N ; i++)
  {
    //evolve
    my_trap.evolve_RK4(k_tot, dt, exchange);

    for (int j = 0 ; j < n ; j++)
    {
      //extract new v and r
      arma::vec v_new = my_trap.get_v(j);
      arma::vec r_new = my_trap.get_r(j);

      V.slice(j).row(i) = v_new.t(); //had to transpose it
      R.slice(j).row(i) = r_new.t();
    }

    t(i) = dt*i;
  }

  V.save("V.bin");
  R.save("R.bin");
  t.save("t.bin");

  return 0;
}
