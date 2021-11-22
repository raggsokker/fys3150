import numpy as np
import matplotlib.pyplot as plt

#extract values for 2x2 lattice
e_O,absm_O = np.loadtxt("2x2_ordered_T=1.txt", usecols=(1,2), unpack=True)
e_U,absm_U = np.loadtxt("2x2_unordered_T=1.txt", usecols=(1,2), unpack=True)

#extract values for 20x20 lattice
e_O1,absm_O1 = np.loadtxt("20x20_ordered_T=1.txt", usecols=(1,2), unpack=True)
e_U1,absm_U1 = np.loadtxt("20x20_unordered_T=1.txt", usecols=(1,2), unpack=True)
e_O2,absm_O2 = np.loadtxt("20x20_ordered_T=2,4.txt", usecols=(1,2), unpack=True)
e_U2,absm_U2 = np.loadtxt("20x20_unordered_T=2,4.txt", usecols=(1,2), unpack=True)


#monte carlo linspace
MC_cycles1 = np.arange(1,1001,1) #for 2x2
MC_cycles2 = np.arange(1,2001,1) #for 20x20


#plot
#latex font
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

"""
for 2x2 lattice
"""
#energy per spin
#plt.plot(MC_cycles1,e_U,label='unordered and T = 1 [J/k]')
#plt.plot(MC_cycles1,e_O,label='ordered and T = 1 [J/k]')
#plt.xlabel('MC cycles')
#plt.ylabel('average energy per spin [J]')

#magnetization per spin
#plt.plot(MC_cycles1,absm_U,label='unordered and T = 1 [J/k]')
#plt.plot(MC_cycles1,absm_O,label='ordered and T = 1 [J/k]')
#plt.xlabel('MC cycles')
#plt.ylabel('average magnetization per spin')

"""
for 20x20 lattice
"""

#energy per spin
plt.plot(MC_cycles2,e_U1,label='unordered and T = 1 [J/k]')
plt.plot(MC_cycles2,e_O1,label='ordered and T = 1 [J/k]')
plt.plot(MC_cycles2,e_U2,label='unordered and T = 2.4 [J/k]')
plt.plot(MC_cycles2,e_O2,label='ordered and T = 2.4 [J/k]')
plt.xlabel('MC cycles')
plt.ylabel('average energy per spin [J]')

#magnetization per spin
#plt.plot(MC_cycles2,absm_U1,label='unordered and T = 1 [J/k]')
#plt.plot(MC_cycles2,absm_O1,label='ordered and T = 1 [J/k]')
#plt.plot(MC_cycles2,absm_U2,label='unordered and T = 2.4 [J/k]')
#plt.plot(MC_cycles2,absm_O2,label='ordered and T = 2.4 [J/k]')
#plt.xlabel('MC cycles')
#plt.ylabel('average magnetization per spin')

plt.legend()
plt.savefig("20x20_ene.pdf")
#plt.show()