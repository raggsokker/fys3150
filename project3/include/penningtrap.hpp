#ifndef __penningtrap_hpp__
#define __penningstrap_hpp__


#include <armadillo>
#include <iostream>
#include <vector>
#include <math.h>
#include "particle.hpp"

class penningtrap
{
  public:

    double B_;
    double V_;
    double d_;
    double f_;
    double omega_V_;
    std::vector<particle> particle_;

    // Constructor
    penningtrap(double B_in,double V_in,double d_in,double f_in = 0,double omega_V_in = 0);


    // Method that adds a particle to the trap
    void add_particle(double q_in,double  m_in,arma::vec v_in,arma::vec r_in);

    // Method that returns the number of particles in trap
    int particle_count();

    //removes element from member vector
    void remove(int i);

    //method that returns the position of particle i
    arma::vec get_r(int i);

    //method that returns the velocity of particle i
    arma::vec get_v(int i);

    //evaluating the electric force on particle i
    arma::vec E_accel(arma::vec r,double t = 0);

    //evaluating the magnetic force on particle i
    arma::vec B_accel(arma::vec v,arma::vec r);

    // Force on particle_i from particle_j
    arma::vec accel_particle(double k_tot,arma::vec r_i, arma::vec r_j);

    // The total force on particle_i from the external fields
    arma::vec total_accel_external(arma::vec r,arma::vec v,double t=0);

    // The total force on particle_i from the other particles
    arma::vec total_accel_particles(double k_tot,int i, arma::vec r_i);

    // The total force on particle_i from both external fields and other particles
    arma::vec total_accel(double k_tot,int i,arma::vec r, arma::vec v,double t = 0);

    // Evolve the system one time step (dt) using Runge-Kutta 4th order
    void evolve_RK4(double k_tot, double dt,int exchange,double t = 0);

    // Evolve the system one time step (dt) using Forward Euler
    void evolve_forward_Euler(double k_tot, double dt,int exchange,double t = 0);


};





#endif
