#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

//define function that evaluates u(x) exact

double func(double x)
{
  return 1 - (1 - exp(-10))*x - exp(-10*x);
}



int main()
{

  // Parameters for output formatting
  int width = 18;
  int prec  = 10;


  // Output a header
  std::cout << "#" << std::setw(width-1) << "x"
            << std::setw(width) << "u"
            << std::endl;


  //define steps n and delta_x
  int n = 100;
  double delta_x = 1/n;

  //make a vector
  //std::vector<double> u;
  //std::vector<double> x;

  //make a loop and insert values in vector u and x

  for (int i = 0; i<= n; i++){
    //u.push_back(func(i*delta_x));
    //x.push_back(i*delta_x);
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
