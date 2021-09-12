#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

//define function that makes use of the forward substitution for b_i

double forward_sub_b(double d, double b, double b_back)
{
  return b - d/b_back;
}


//define function that makes use of the forward substitution for g_i

double forward_sub_g(double a, double b_back, double g, double g_back)
{
  return g - a*g_back/b_back;
}

//define function that makes use of the backward substitution for g_i

double backward_sub_v(double b, double c, double g, double v_forward)
{
  return (g - c*v_forward)/b;
}

//define function for g

double f(double x,double h)
{
  return 100*exp(-10*x)*h*h;
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
  double n = 1000;
  double delta_x = 1/n;
  double h = delta_x; //this seems odd. Had to make a destinction between them for plugging in function f later


  //define start value and end value for x and v

  double v0 = 0;
  double v1 = 0;
  double x0 = 0;
  double x1 = n*delta_x;

  // Output to screen
  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x0
            << std::setw(width) << std::setprecision(prec) << std::scientific << v0
            << std::endl;


  //make vectors a,b,c and d these are now numbers
  int a = -1;
  int b = 2;
  int c = -1;
  int d = a*c;

  //make vectors b_tilde and g_tilde

  std::vector<double> b_tilde(n-2,0);
  std::vector<double> g_tilde(n-2,0);

  //initial values for b_tilde and g_tilde
  b_tilde.at(0) = b;
  g_tilde.at(0) = f(0,h) + v0;

  //make a loop and insert values in vector b_tilde and g_tilde

  for (int i = 1; i<= n-3; i++){

    //b_tilde.push_back(forward_sub_b(a.at(i),b.at(i), b_tilde.at(i-1), c.at(i-1)));
    //g_tilde.push_back(forward_sub_g(a.at(i), b_tilde.at(i-1), f(i*delta_x), g_tilde.at(i-1)));
    b_tilde.at(i) = forward_sub_b(d ,b, b_tilde.at(i-1));
    g_tilde.at(i) = forward_sub_g(a, b_tilde.at(i-1), f(i*delta_x,h), g_tilde.at(i-1));

  }
  //update last g_tilde (as it needs to be added by v1)
  g_tilde.at(n-3) = g_tilde.at(n-3) + v1;

  //make vector v where our solutions will be in and update last element in it
  std::vector<double> v(n-2, 0);
  v.at(n-3) = g_tilde.at(n-3)/b_tilde.at(n-3);

  //insert values in v using for loop

  for (int i = n-4; i >= 0;i--)
  {
    v.at(i) = backward_sub_v(b_tilde.at(i), c, g_tilde.at(i), v.at(i+1));
  }

  //make vector x where v will be evaluated
  std::vector<double> x(n-2,0);

  //insert values in x using for loop

  for (int i = 1; i<= n-3; i++)
  {
    x.at(i) = i*delta_x;
  }

  //print output

  for (int i = 1; i<= n-3; i++)
  {
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x.at(i)
              << std::setw(width) << std::setprecision(prec) << std::scientific << v.at(i)
              << std::endl;
  }


  //print last x1 and v1 values

  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x1
            << std::setw(width) << std::setprecision(prec) << std::scientific << v1
            << std::endl;

  // Return 0 when done
  return 0;
}
