#include "print.hpp"


void print(arma::vec average,double T,int N,int mcc,std::string filename)
{
  std::ofstream ofile;
  ofile.open(filename, std::ofstream::app);
  
  // Some width and precision parameters we will use to format the output
  int width = 12;
  int prec  = 4;

  //add header
  //std::cout << "#" << std::setw(12) << "T" << std::setw(12) << "e" << std::setw(12) << "e^2"
  //          << std::setw(12) << "abs(m)" << std::setw(12) << "m^2"
  //          << std::endl;


  double T_2 = T*T;
  double C_v = (average(1)/mcc - average(0)*average(0)/mcc/mcc)/N/T_2; //heat capacity
  double chi = (average(3)/mcc - average(2)*average(2)/mcc/mcc)/N/T; //susceptibility
  //double variance = average(1)/mcc/N - average(0)*average(0)/mcc/mcc/N/N; //variance

  // Write to file
  ofile << std::setw(width) << std::setprecision(prec) << std::scientific << T //temperature
        << std::setw(width) << std::setprecision(prec) << std::scientific << average(0)/mcc/N //average energy per spin
        << std::setw(width) << std::setprecision(prec) << std::scientific << average(2)/mcc/N //average magnetization per spin
        << std::setw(width) << std::setprecision(prec) << std::scientific << C_v //heat capacity
        << std::setw(width) << std::setprecision(prec) << std::scientific << chi //susceptibility
        << std::endl;

  // Close the output file
  ofile.close();
}
