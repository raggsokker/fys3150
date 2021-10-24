#include "penningtrap.hpp"
#include "particle.hpp"

//Constructor
penningtrap::penningtrap(double B_in,double V_in,double d_in,double f_in,double omega_V_in)
{
  B_ = B_in;
  V_ = V_in;
  d_ = d_in;
  f_ = f_in;
  omega_V_ = omega_V_in;
}

// Method that adds a particle to the trap
void penningtrap::add_particle(double q_in,double  m_in,arma::vec v_in,arma::vec r_in)
{
  // Create a new particle from particle class
  particle p_in(q_in, m_in, v_in, r_in);

  //add to member vector
  particle_.push_back(p_in);
}

// Method that returns the number of particles in trap
int penningtrap::particle_count()
{
  return particle_.size();
}

//removes element from member vector
void penningtrap::remove(int i)
{
  particle_.erase(particle_.begin()+i);
}

//method that returns the position of particle i
arma::vec penningtrap::get_r(int i)
{
  return particle_[i].get_particle_r();
}

//method that returns the velocity of particle i
arma::vec penningtrap::get_v(int i)
{
  return particle_[i].get_particle_v();
}

//evaluating the electric acceleration on particle
arma::vec penningtrap::E_accel(arma::vec r,double t)
{
  //variables
  double q = particle_[0].get_particle_q(); //just pick one. They are all the same
  double m = particle_[0].get_particle_m(); //
  double V0 = V_*(1 + f_*cos(omega_V_*t));
  double V0_d_squared = V0/(d_*d_);

  //omega_z^2
  double omega_z_squared = 2*q*V0_d_squared/m;
  arma::vec E_accel;
  if (arma::norm(r) < d_)
  {
    E_accel = {0.5*omega_z_squared*r(0),  0.5*omega_z_squared*r(1), - omega_z_squared*r(2)};
  }
  else
  {
    E_accel = {0,0,0};
  }

  return E_accel;
}

//evaluating the magnetic acceleration on particle
arma::vec penningtrap::B_accel(arma::vec v,arma::vec r)
{
  //variables
  double q = particle_[0].get_particle_q();
  double m = particle_[0].get_particle_m();

  //omega_0
  double omega_0 = q*B_/m;

  arma::vec B_accel;

  if (arma::norm(r) < d_)
  {
    B_accel = {-omega_0*v(1) , omega_0*v(0), 0};
  }
  else
  {
    B_accel = {0,0,0};
  }

  return B_accel;
}

// The total acceleration on particle_i from the external fields
arma::vec penningtrap::total_accel_external(arma::vec r,arma::vec v,double t)
{
  arma::vec total_accel_external = E_accel(r,t) + B_accel(v,r);
  return total_accel_external;
}


// acceleration on particle_i from particle_j
arma::vec penningtrap::accel_particle(double k_tot,arma::vec r_i, arma::vec r_j)
{

  double norm_third = pow(arma::norm(r_i - r_j),3);
  arma::vec accel_particle = {k_tot*(r_i(0) - r_j(0))/norm_third,k_tot*(r_i(1) - r_j(1))/norm_third,k_tot*(r_i(2) - r_j(2))/norm_third};
  return accel_particle;
}


// The total acceleration on particle_i from the other particles
arma::vec penningtrap::total_accel_particles(double k_tot,int i ,arma::vec r_i)
{

  int n = particle_count();
  arma::vec total_accel_particles = {0,0,0};

  for (int j = 0; j < n; j++)
  {
    if (j != i)
    {
      arma::vec r_j = get_r(j);
      total_accel_particles +=  accel_particle(k_tot,r_i,r_j);
    }
  }
  return total_accel_particles;
}

// The total acceleration on particle_i from both external fields and other particles
arma::vec penningtrap::total_accel(double k_tot,int i,arma::vec r, arma::vec v,double t)
{
  arma::vec total_accel = total_accel_external(r,v,t) + total_accel_particles(k_tot,i ,r);
  return total_accel;
}


// Evolve the system one time step (dt) using Runge-Kutta 4th order
void penningtrap::evolve_RK4(double k_tot, double dt,int exchange,double t)
{

  int n = particle_count();
  //new v and r
  arma::mat v_new = arma::mat(n,3);
  arma::mat r_new = arma::mat(n,3);

  if (exchange == false)
  {
    for (int i = 0; i < n; i++)
    {
      //old v and r
      arma::vec v_old = get_v(i);
      arma::vec r_old = get_r(i);

      //RK4 for velocity
      //calc k1,k2...
      arma::vec k1 = dt*total_accel_external(r_old,v_old,t);
      arma::vec k2 = dt*total_accel_external(r_old + k1/2,v_old + k1/2,t + dt/2);
      arma::vec k3 = dt*total_accel_external(r_old + k2/2,v_old + k2/2, t + dt/2);
      arma::vec k4 = dt*total_accel_external(r_old + k3, v_old + k3, t + dt);
      arma::vec tot = v_old + (k1 + 2*k2 + 2*k3 + k4)/6;
      v_new.row(i) = tot.t();

      //RK4 for position
      r_new.row(i) = r_old.t() + dt*(v_old.t() + v_new.row(i))/2;

    }

    for (int i = 0; i < n; i++)
    {
      //update particle members
      particle_[i].update_particle_velocity(v_new.row(i).t());
      particle_[i].update_particle_position(r_new.row(i).t());
    }
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      //old v and r
      arma::vec v_old = get_v(i);
      arma::vec r_old = get_r(i);

      //RK4 for velocity
      //calc k1,k2...
      arma::vec k1 = dt*total_accel(k_tot,i,r_old,v_old,t);
      arma::vec k2 = dt*total_accel(k_tot,i,r_old + k1/2,v_old + k1/2,t + dt/2);
      arma::vec k3 = dt*total_accel(k_tot,i,r_old + k2/2,v_old + k2/2,t + dt/2);
      arma::vec k4 = dt*total_accel(k_tot,i,r_old + k3, v_old + k3, t + dt);
      arma::vec tot = v_old + (k1 + 2*k2 + 2*k3 + k4)/6;
      v_new.row(i) = tot.t();

      //RK4 for position
      r_new.row(i) = r_old.t() + dt*(v_old.t() + v_new.row(i))/2;

    }

    for (int i = 0; i < n; i++)
    {
      //update particle members
      particle_[i].update_particle_velocity(v_new.row(i).t());
      particle_[i].update_particle_position(r_new.row(i).t());
    }
  }


}


// Evolve the system one time step (dt) using Forward Euler
void penningtrap::evolve_forward_Euler(double k_tot, double dt,int exchange,double t)
{

  int n = particle_count();
  //new v and r
  arma::mat v_new = arma::mat(n,3);
  arma::mat r_new = arma::mat(n,3);

  if (exchange == false)
  {
    for (int i = 0; i < n; i++)
    {
      //old v and r
      arma::vec v_old = get_v(i);
      arma::vec r_old = get_r(i);

      arma::vec f = total_accel_external(r_old,v_old,t);

      v_new.row(i) = v_old.t() + dt*f.t();
      r_new.row(i) = r_old.t() + dt*v_old.t();
    }

    for (int i = 0; i < n; i++)
    {
      //update particle members
      particle_[i].update_particle_velocity(v_new.row(i).t());
      particle_[i].update_particle_position(r_new.row(i).t());
    }
  }
  else
  {

    for (int i = 0; i < n; i++)
    {
      //old v and r
      arma::vec v_old = get_v(i);
      arma::vec r_old = get_r(i);

      arma::vec f = total_accel(k_tot,i,r_old,v_old,t);

      v_new.row(i) = v_old.t() + dt*f.t();
      r_new.row(i) = r_old.t() + dt*v_old.t();
    }

    for (int i = 0; i < n; i++)
    {
      //update particle members
      particle_[i].update_particle_velocity(v_new.row(i).t());
      particle_[i].update_particle_position(r_new.row(i).t());
    }
  }
}
