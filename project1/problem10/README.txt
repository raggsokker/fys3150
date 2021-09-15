NOTE: I see now, that the generaltime.cpp is the same codefile as specialtime.cpp (for some odd reason). The generaltime.cpp should be the same as the code from problem7.cpp

code that evaluates v_i's using the special and the general algorithm. Writes the computation time to file and plots the time.

My computation time's for N = 100,...,1000000 are attached.

specialtime.cpp
-----------
C++ code that computes the runtime for the special algorithm

Build command: g++ specialtime.cpp -o specialtime.exe
Run command: ./specialtime.exe


generaltime.cpp
-----------
C++ code that computes the runtime for the general algorithm

Build command: g++ generaltime.cpp -o generaltime.exe
Run command: ./generaltime.exe

plot_time.py
-------
Python script that reads the data and plots the time's


Run command: python3 plot_time.py