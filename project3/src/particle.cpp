#include "particle.hpp"


// Constructor
particle::particle(double q_in, double m_in,arma::vec v_in, arma::vec r_in)
{
  q_ = q_in;
  m_ = m_in;
  v_ = v_in;
  r_ = r_in;
}

//get position of particle
arma::vec particle::get_particle_r()
{
  return r_;
}

//get velocity of particle
arma::vec particle::get_particle_v()
{
  return v_;
}

//get charge of particle
double particle::get_particle_q()
{
  return q_;
}

//get mass of particle
double particle::get_particle_m()
{
  return m_;
}

//update particle velocity
void particle::update_particle_velocity(arma::vec v)
{
  v_ = v;
}

//update particle position
void particle::update_particle_position(arma::vec r)
{
  r_ = r;
}
