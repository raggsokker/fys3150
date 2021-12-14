Code for solving Project 5
---------------------------

All the usefull functions are contained in "src" together with the header files
contained in "include".


main.cpp
-----------------

evolves the wave-function U using the Crank-Nicolson approach


animate.py
----------

Animates the wavefunction


deviation.py
----------

plots the deviation from 1 as a function of time


plot.py
----------

plots the 3D wavefunction with imshow from matplotlib. Also plots the marginalized wavefunction


How to build and run the programs
---------------------------------

For c++ code:

- main_xxx.cpp

    Build: g++ main.cpp src/*.cpp -I include  -o main.exe
    Run: ./main_xxx.exe


For python code:
- xxx.py
    
    Run command: python3 xxx.py
