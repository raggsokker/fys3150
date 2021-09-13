import numpy as np
import matplotlib.pyplot as plt

#extract values
x100,v100 = np.loadtxt("N100.txt", usecols=(0,1), unpack=True)
x1000,v1000 = np.loadtxt("N1000.txt", usecols=(0,1), unpack=True)
x10000,v10000 = np.loadtxt("N10000.txt", usecols=(0,1), unpack=True)
x100000,v100000 = np.loadtxt("N100000.txt", usecols=(0,1), unpack=True)
x1000000,v1000000 = np.loadtxt("N1000000.txt", usecols=(0,1), unpack=True)

#put them in list
x = np.array([x100,x1000,x10000,x100000,x1000000])
v = np.array([v100,v1000,v10000,v100000,v1000000])

#define functions for error and u (exact function)
def abs_error(u,v):
    return np.log10(np.abs(u-v))

def rel_error(u,v):
    return np.log10(np.abs((u-v)/u))

def u(x):
    return 1 - (1-np.exp(-10))*x - np.exp(-10*x)


#Plotting

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

#Absolute error
for i in range(len(x)):
    xplot = x[i][1:-2] #division by zero error when last x
    yplot = abs_error(u(x[i]),v[i])[1:-2]
    plt.plot(xplot,yplot, label=f'N = {10**(i+2)}')

plt.title('$log_{10} (absolute \; error)$')
plt.xlabel('x')
plt.ylabel('$log_{10} (absolute \; error)$')
plt.legend()
plt.savefig("log10(abs_error)")
#plt.show()


#Relative error
for i in range(len(x)):
    xplot = x[i][1:-2] #division by zero error when last x
    yplot = rel_error(u(x[i]),v[i])[1:-2]
    plt.plot(xplot,yplot, label=f'N = {10**(i+2)}')

plt.title('$log_{10} (relative \; error)$')
plt.xlabel('x')
plt.ylabel('$log_{10} (relative \; error)$')
plt.legend()
plt.savefig("log10(rel_error)")
#plt.show()


#Table for maximum relative error
print('N     relative error')
for i in range(len(x)):
    print(f'{10**(i+2)}  {np.max(rel_error(u(x[i]),v[i])[1:-2])}')

