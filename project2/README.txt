Code for solving Project 2
---------------------------

All the usefull functions are contained in "src"together with the header files
contained in "include".

Also added some textfiles for my runs "scaling.txt", "solution_10n.txt" and "solution_100n.txt"


main_problem3.cpp
-----------------

Code that sets up a tridiagonal matrix and finds its eigenvalue/vectors using
both the analytical method and armadillo.


main_test_max.cpp
-----------------

Finds the max abs value in the off diagonal of a matrix and prints out the value
and its index


main_test_jacobi.cpp
--------------------

Uses Jacobi's method to find the eigenvalues/vectors and compares it to
the analytical results


main_scaling.cpp
----------------

Finds how many rotations (iterations) the program needs to solve for its
eigenvalues/vectors using Jacobi's method for different n's.


main_solution.cpp
-----------------

Finds the solution eigenvectors corresponding to the three lowest eigenvalues using Jacobi's method and
prints the solution to file. Also prints out the analytical solutions


scaling.py
----------

Finds the best fit curve for the "iterations vs N" and plots the result


solution.py
----------

Plots the solutions


How to build and run the programs
---------------------------------

For c++ code:

- main_xxx.cpp
  
    Build: g++ main_xxx.cpp src/*.cpp -I include -o main_xxx.exe
    Run: ./main_xxx.exe


For python code:
- xxx.py
    
    Run command: python3 xxx.py
