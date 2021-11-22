import numpy as np
import matplotlib.pyplot as plt

#extract values 20000 samples
e1 = np.loadtxt("20x20_hist_T=1.txt", usecols=(1), unpack=True)
e2 = np.loadtxt("20x20_hist_T=2,4.txt", usecols=(1), unpack=True)
#mean
mean1 = np.loadtxt("20x20_mean_T=1.txt", usecols=(0), unpack=True)
mean2 = np.loadtxt("20x20_mean_T=2,4.txt", usecols=(0), unpack=True)

#compute variance
var1 = 0
var2 = 0
for i in range(len(e1)):
    var1 += 1 / len(e1) * (e1[i] - mean1) ** 2
    var2 += 1/ len(e2) * (e2[i] - mean2)**2

#print(var1) #5.9e-5 [energy per spin]
#print(var2) #0.02 [energy per spin]


#plot

#latex font
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

#plt.hist(e1,bins=100,density=True,ec = 'black',label='T = 1 J/k')
plt.hist(e2,bins=101,density=True,ec = 'black',label='T = 2.4 J/k')
plt.text(-0.9,2.3, 'variance = 0.02', horizontalalignment='center',
     verticalalignment='center')
plt.legend()
plt.xlabel('energy per spin')
plt.ylabel('frequency')

plt.savefig("20x20_histo2.pdf")
#plt.show()