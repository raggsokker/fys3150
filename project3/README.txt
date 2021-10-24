Code for solving Project 3
---------------------------

All the usefull functions are contained in "src"together with the header files
contained in "include".


main_test.cpp
-----------------

Code that evolves the system using RK4/FE and saves the velocity/position data


main_trapped.cpp
-----------------

Code that evolves the system using RK4/FE for many particles with random initial conditions from armadillo random


test.py
----------

plots the velocitites and positions


particle_count.py
----------

plots the number of particles inside penningtrap


How to build and run the programs
---------------------------------

For c++ code:

- main_xxx.cpp
  
    Build: g++ main_xxx.cpp src/*.cpp -I include -o main_xxx.exe
    Run: ./main_xxx.exe

    Note! Sometimes had to add "-O1 -larmadillo" after the build command in some cases (idk why)
    Example: g++ main_xxx.cpp src/*.cpp -I include -o main_xxx.exe -O1 -larmadillo	

For python code:
- xxx.py
    
    Run command: python3 xxx.py
