import numpy as np
import matplotlib.pyplot as plt

#extract files
x100,v100 = np.loadtxt("N100.txt", usecols=(0,1), unpack=True)
x1000,v1000 = np.loadtxt("N1000.txt", usecols=(0,1), unpack=True)
x10000,v10000 = np.loadtxt("N10000.txt", usecols=(0,1), unpack=True)
x100000,v100000 = np.loadtxt("N100000.txt", usecols=(0,1), unpack=True)
x1000000,v1000000 = np.loadtxt("N1000000.txt", usecols=(0,1), unpack=True)

#put them in list

x = np.array([x100,x1000,x10000,x100000,x1000000])
v = np.array([v100,v1000,v10000,v100000,v1000000])

#define function for exact value

def u(x):
    return 1 - (1-np.exp(-10))*x - np.exp(-10*x)


#Plot
# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

for i in range(len(x)):
    xplot = x[i]
    yploy = v[i]
    plt.plot(xplot,yploy,'--',label=f'N = {10**(i+2)}')

plt.plot(x[-1],u(x[-1]),label='u(x) exact')
plt.legend()
plt.title('u(x) and v(x)')
plt.xlabel('x')
plt.ylabel('u(x) and v(x)')
plt.savefig("u_exact_vs_v.pdf")
#plt.show()