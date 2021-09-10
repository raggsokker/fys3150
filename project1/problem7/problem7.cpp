#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

//define function that makes use of the forward substitution for b_i

double forward_sub_b(int a, int b, int b_back, int c_back)
{
  return b - a*c_back/b_back;
}


//define function that makes use of the forward substitution for g_i

double forward_sub_g(int a, int b_back, int g, int g_back)
{
  return g - a*g_back/b_back;
}

//define function that makes use of the backward substitution for g_i

double backward_sub_v(int b, int c, int g, int v_forward)
{
  return g - a*g_back/b_back;
}


int main()
{

  // Parameters for output formatting
  int width = 18;
  int prec  = 10;


  // Output a header
  std::cout << "#" << std::setw(width-1) << "x"
            << std::setw(width) << "v"
            << std::endl;


  //define steps n and delta_x
  int n = 100;
  double delta_x = 1/n;


  //define start value and end value for x and v

  double v0 = 0
  double v1 = 0
  double x0 = 0
  double x1 = n*delta_x

  // Output to screen
  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x0
            << std::setw(width) << std::setprecision(prec) << std::scientific << v0
            << std::endl;

  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x1
            << std::setw(width) << std::setprecision(prec) << std::scientific << v1
            << std::endl;


  //make vectors a,b an c
  //std::vector<type> a(n-3, -1);
  //std::vector<type> b(n-2, 2);
  //std::vector<type> c(n-3, -1);
  int a = -1
  int b = 2
  int c = -1

  //make vectors b_tilde and g_tilde

  std::vector<double> b_tilde;
  std::vector<double> g_tilde;

  //initial values for b_tilde and g_tilde
  b_tilde.at(0) = b.at(0)
  g_tilde.at(0) = 100*exp(-10*delta_x)*h*h + v0

  //make a loop and insert values in vector b_tilde and x_tilde

  for (int i = 1; i<= n-1; i++){

    b_tilde.push_back(forward_sub_b(a,b, b_tilde.at(0), c));
    g_tilde.push_back(forward_sub_g(a, b_tilde.at(0), int g, int g_back));
    //std::cout << '\n' << u.at(i);
    //std::cout << '\n' << x.at(i);

    // Output to screen
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << i*delta_x
              << std::setw(width) << std::setprecision(prec) << std::scientific << func(i*delta_x)
              << std::endl;

  }




  // Return 0 when done
  return 0;
}
