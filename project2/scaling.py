import numpy as np
import matplotlib.pyplot as plt

#extract values
N , iterations = np.loadtxt("scaling.txt", usecols=(0,1), unpack=True)

#polyfit
"""
The curve looks like a x^2 graph. I tried polyfit for
x^2, x^3 and x^4. x^2 gave best results, so we stick with that
"""
P = np.polyfit(N,iterations,2) #behaves like 1.8*N^2
x = np.linspace(min(N),max(N),1000)
y = P[0]*x**2 + P[1]*x + P[2]


#Plotting

# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

plt.plot(x,y,label='best fit curve')
plt.scatter(N,iterations,color='red',label='iterations')
plt.title('Iterations vs N')
plt.xlabel('N')
plt.ylabel('Iterations')
plt.legend()
plt.savefig("scaling.pdf")
#plt.show()