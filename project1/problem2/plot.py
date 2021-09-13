import numpy as np
import matplotlib.pyplot as plt

x,u = np.loadtxt("output.txt", usecols=(0,1), unpack=True)


# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
plt.scatter(x,u)
plt.title('u(x)')
plt.xlabel('x')
plt.ylabel('u')
plt.savefig("u_exact.pdf")
#plt.show()
