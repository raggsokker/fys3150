
#ifndef __particle_hpp__
#define __particle_hpp__

#include <armadillo>
#include <iostream>
#include <math.h>


class particle
{
  public:
    double q_;
    double m_;
    arma::vec v_;
    arma::vec r_;

    // Constructor
    particle(double q_in, double m_in,arma::vec v, arma::vec r);

    //method for obtaining position of particle
    arma::vec get_particle_r();

    //method for obtaining velocity of particle
    arma::vec get_particle_v();

    //get charge of particle
    double get_particle_q();

    //get mass of particle
    double get_particle_m();

    //update particle velocity
    void update_particle_velocity(arma::vec v);

    //update particle position
    void update_particle_position(arma::vec r);


};

#endif
