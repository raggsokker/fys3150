import numpy as np
import matplotlib.pyplot as plt

#extract values
Jacobi1_10n,Jacobi2_10n,Jacobi3_10n,analytic1_10n,analytic2_10n,analytic3_10n = np.loadtxt("solution_10n.txt", usecols=(0,1,2,3,4,5), unpack=True)
Jacobi1_100n,Jacobi2_100n,Jacobi3_100n,analytic1_100n,analytic2_100n,analytic3_100n = np.loadtxt("solution_100n.txt", usecols=(0,1,2,3,4,5), unpack=True)

#adding boundary condition to front and tail for all solutions
Jacobi1_10n = np.concatenate([[0],Jacobi1_10n,[0]])
Jacobi2_10n = np.concatenate([[0],Jacobi2_10n,[0]])
Jacobi3_10n = np.concatenate([[0],Jacobi3_10n,[0]])

analytic1_10n = np.concatenate([[0],analytic1_10n,[0]])
analytic2_10n = np.concatenate([[0],analytic2_10n,[0]])
analytic3_10n = np.concatenate([[0],analytic3_10n,[0]])

Jacobi1_100n = np.concatenate([[0],Jacobi1_100n,[0]])
Jacobi2_100n = np.concatenate([[0],Jacobi2_100n,[0]])
Jacobi3_100n = np.concatenate([[0],Jacobi3_100n,[0]])

analytic1_100n = np.concatenate([[0],analytic1_100n,[0]])
analytic2_100n = np.concatenate([[0],analytic2_100n,[0]])
analytic3_100n = np.concatenate([[0],analytic3_100n,[0]])

#x values
x10 = np.linspace(0,1,11)
x100 = np.linspace(0,1,101)

#plot

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

#n = 10

#lowest eigenvalue
#plt.plot(x10,Jacobi1_10n,label='Jacobi')
#plt.plot(x10,analytic1_10n,label='Analytical')
plt.title('$\hatx \; vs \; v$ for n = 10')
plt.legend()
plt.xlabel('$\hatx$')
plt.ylabel('v')
#plt.savefig("10n_1.pdf")

#2. lowest eigenvalue
#plt.plot(x10,Jacobi2_10n,label='Jacobi')
#plt.plot(x10,analytic2_10n,label='Analytical')
plt.title('$\hatx \; vs \; v$ for n = 10')
plt.legend()
plt.xlabel('$\hatx$')
plt.ylabel('v')
#plt.savefig("10n_2.pdf")

#3. lowest eigenvalue
#plt.plot(x10,Jacobi3_10n,label='Jacobi')
#plt.plot(x10,analytic3_10n,label='Analytical')
plt.title('$\hatx \; vs \; v$ for n = 10')
plt.legend()
plt.xlabel('$\hatx$')
plt.ylabel('v')
#plt.savefig("10n_3.pdf")

#n = 100

#lowest eigenvalue
#plt.plot(x100,Jacobi1_100n,label='Jacobi')
#plt.plot(x100,analytic1_100n,label='Analytical')
plt.title('$\hatx \; vs \; v$ for n = 100')
plt.legend()
plt.xlabel('$\hatx$')
plt.ylabel('v')
#plt.savefig("100n_1.pdf")

#2. lowest eigenvalue
#plt.plot(x100,Jacobi2_100n,label='Jacobi')
#plt.plot(x100,analytic2_100n,label='Analytical')
plt.title('$\hatx \; vs \; v$ for n = 100')
plt.legend()
plt.xlabel('$\hatx$')
plt.ylabel('v')
#plt.savefig("100n_2.pdf")

#3. lowest eigenvalue
plt.plot(x100,Jacobi3_100n,label='Jacobi')
plt.plot(x100,analytic3_100n,label='Analytical')
plt.title('$\hatx \; vs \; v$ for n = 100')
plt.legend()
plt.xlabel('$\hatx$')
plt.ylabel('v')
plt.savefig("100n_3.pdf")

