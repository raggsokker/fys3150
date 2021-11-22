Code for solving Project 4
---------------------------

All the usefull functions are contained in "src"together with the header files
contained in "include".


main_para_over_MC.cpp
-----------------

evolves the spin matrix using the metropolis algorithm with parallelization over the MCMC loop.
Prints out point estimates


main_para_over_T.cpp
-----------------

evolves the spin matrix using the metropolis algorithm with parallelization over the temperature loop.
Prints out point estimates


test.py
----------

Plots the point estimates for a 2x2 and 20x20 lattice


histogram.py
----------

plots the full probability distribution for energy for a 20x20 lattice for T = 1 and 2.4

find_Tc.py
----------

plots the point estimates for different lattice sizes, and one can maybe read of the critical temperature


How to build and run the programs
---------------------------------

For c++ code:

- main_xxx.cpp
 - With parallelization:
  
    Build: g++ main_xxx.cpp src/*.cpp -I include -fopenmp  -o main_xxx.exe
    Run: ./main_xxx.exe

  - Without parallelization:
  
    Build: g++ main_xxx.cpp src/*.cpp -I include  -o main_xxx.exe
    Run: ./main_xxx.exe


For python code:
- xxx.py
    
    Run command: python3 xxx.py
