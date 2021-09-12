import numpy as np
import matplotlib.pyplot as plt

x100,u100 = np.loadtxt("N100.txt", usecols=(0,1), unpack=True)
x1000,u1000 = np.loadtxt("N1000.txt", usecols=(0,1), unpack=True)
x10000,u10000 = np.loadtxt("N10000.txt", usecols=(0,1), unpack=True)
x100000,u100000 = np.loadtxt("N100000.txt", usecols=(0,1), unpack=True)
x1000000,u1000000 = np.loadtxt("N1000000.txt", usecols=(0,1), unpack=True)


# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
plt.plot(x,u)
plt.plot(x,u)
plt.plot(x,u)
plt.plot(x,u)
plt.plot(x,u)
plt.title('u(x)')
plt.xlabel('x')
plt.ylabel('u')
#plt.savefig("u_exact")
plt.show()