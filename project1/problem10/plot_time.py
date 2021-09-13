import numpy as np
import matplotlib.pyplot as plt

#extract values
tau_special_1000 = np.loadtxt("Nspecial1000.txt", usecols=(0), unpack=True)
tau_special_10000 = np.loadtxt("Nspecial10000.txt", usecols=(0), unpack=True)
tau_special_100000 = np.loadtxt("Nspecial100000.txt", usecols=(0), unpack=True)
tau_special_1000000 = np.loadtxt("Nspecial1000000.txt", usecols=(0), unpack=True)

tau_general_1000 = np.loadtxt("Ngeneral1000.txt", usecols=(0), unpack=True)
tau_general_10000 = np.loadtxt("Ngeneral10000.txt", usecols=(0), unpack=True)
tau_general_100000 = np.loadtxt("Ngeneral100000.txt", usecols=(0), unpack=True)
tau_general_1000000 = np.loadtxt("Ngeneral1000000.txt", usecols=(0), unpack=True)

#define N array

N = np.array([1000,10000,100000,1000000])

#store all tau's in array
tau_special = np.array([tau_special_1000,tau_special_10000,tau_special_100000,tau_special_1000000])
tau_general = np.array([tau_general_1000,tau_general_10000,tau_general_100000,tau_general_1000000])

#define function for average time
def mid_tau(tau):
    return np.sum(tau)/len(tau)

#make arrays for mid value's of tau
tau_special_mid = np.zeros(len(N))
tau_general_mid = np.zeros(len(N))

for i in range(len(N)):
    tau_special_mid[i] = mid_tau(tau_special[i])
    tau_general_mid[i] = mid_tau(tau_general[i])


#Plotting

# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

plt.scatter(N,tau_special_mid,marker='x',color='r',linewidths=1,label='special')
plt.scatter(N,tau_general_mid,marker='x',color='b',linewidths=1,label='general')
plt.title('time for special vs general')
plt.xlabel('N')
plt.ylabel('Tau [s]')
plt.legend()
plt.xscale("log")
plt.yscale("log")
#plt.savefig("special_vs_general.pdf")
#plt.show()
