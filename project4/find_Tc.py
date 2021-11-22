import numpy as np
import matplotlib.pyplot as plt


#extract test values
T_test,e_test,absm_test,Cv_test,chi_test = np.loadtxt("L40_100.txt", usecols=(0,1,2,3,4), unpack=True)

#extract values for L = 40,60,80 and 100 with parallelization over Temperatures (10000 MC cycles)
T40,e40,absm40,Cv40,chi40 = np.loadtxt("L40_1000.txt", usecols=(0,1,2,3,4), unpack=True) #1000 temperature points and 500 burn
T60,e60,absm60,Cv60,chi60 = np.loadtxt("L60_200.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 500 burn in
T80,e80,absm80,Cv80,chi80 = np.loadtxt("L80_200.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 500 burn in
T100,e100,absm100,Cv100,chi100 = np.loadtxt("L100_200.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 500 burn in
T100_2,e100_2,absm100_2,Cv100_2,chi100_2 = np.loadtxt("L100_1000.txt", usecols=(0,1,2,3,4), unpack=True) #1000 points and 5000 burn

#extract values for L = 40,60,80 and 100 with parallelization over MCMC (10000 MC cycles)
T40_o,e40_o,absm40_o,Cv40_o,chi40_o = np.loadtxt("L40_200_2.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 1000 burn in
T60_o,e60_o,absm60_o,Cv60_o,chi60_o = np.loadtxt("L60_200_2.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 1000 burn in
T80_o,e80_o,absm80_o,Cv80_o,chi80_o = np.loadtxt("L80_200_2.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 1500 burn in
T100_o,e100_o,absm100_o,Cv100_o,chi100_o = np.loadtxt("L100_200_2.txt", usecols=(0,1,2,3,4), unpack=True) #200 points and 1500 burn in

#around 2.25 to 2.35 zoom in with parallelization over Temperatures

T40_close,e40_close,absm40_close,Cv40_close,chi40_close = np.loadtxt("L40_close_400.txt", usecols=(0,1,2,3,4), unpack=True) #400 points and 2000 burn in
T60_close,e60_close,absm60_close,Cv60_close,chi60_close = np.loadtxt("L60_close_400.txt", usecols=(0,1,2,3,4), unpack=True) #400 points and 2000 burn in
T80_close,e80_close,absm80_close,Cv80_close,chi80_close = np.loadtxt("L80_close_400.txt", usecols=(0,1,2,3,4), unpack=True) #400 points and 2000 burn in
T100_close,e100_close,absm100_close,Cv100_close,chi100_close = np.loadtxt("L100_close_400.txt", usecols=(0,1,2,3,4), unpack=True) #400 points and 2000 burn in

#non para
T40_n,e40_n,absm40_n,Cv40_n,chi40_n = np.loadtxt("L40_nonpara.txt", usecols=(0,1,2,3,4), unpack=True) #400 points and 2000 burn in
T60_n,e60_n,absm60_n,Cv60_n,chi60_n = np.loadtxt("L60_nonpara.txt", usecols=(0,1,2,3,4), unpack=True) #400 points and 2000 burn in


"""
fix indicies as they came out unordered when parallelized over temperatures
"""

#for the zoomed data
idx40_close = np.argsort(T40_close)
idx60_close = np.argsort(T60_close)
idx80_close = np.argsort(T80_close)
idx100_close = np.argsort(T100_close)

T40_close = T40_close[idx40_close]
Cv40_close = Cv40_close[idx40_close]
chi40_close = chi40_close[idx40_close]
e40_close = e40_close[idx40_close]
absm40_close = absm40_close[idx40_close]

T60_close = T60_close[idx60_close]
Cv60_close = Cv60_close[idx60_close]
chi60_close = chi60_close[idx60_close]
e60_close = e60_close[idx60_close]
absm60_close = absm60_close[idx60_close]

T80_close = T80_close[idx80_close]
Cv80_close = Cv80_close[idx80_close]
chi80_close = chi80_close[idx80_close]
e80_close = e80_close[idx80_close]
absm80_close = absm80_close[idx80_close]

T100_close = T100_close[idx100_close]
Cv100_close = Cv100_close[idx100_close]
chi100_close = chi100_close[idx100_close]
e100_close = e100_close[idx100_close]
absm100_close = absm100_close[idx100_close]

#for parallelization over T data
idx40_o = np.argsort(T40_o)
idx60_o = np.argsort(T60_o)
idx80_o = np.argsort(T80_o)
idx100_o = np.argsort(T100_o)

T40_o = T40_o[idx40_o]
Cv40_o = Cv40_o[idx40_o]
chi40_o = chi40_o[idx40_o]
e40_o = e40_o[idx40_o]
absm40_o = absm40_o[idx40_o]

T60_o = T60_o[idx60_o]
Cv60_o = Cv60_o[idx60_o]
chi60_o = chi60_o[idx60_o]
e60_o = e60_o[idx60_o]
absm60_o = absm60_o[idx60_o]

T80_o = T80_o[idx80_o]
Cv80_o = Cv80_o[idx80_o]
chi80_o = chi80_o[idx80_o]
e80_o = e80_o[idx80_o]
absm80_o = absm80_o[idx80_o]

T100_o = T100_o[idx100_o]
Cv100_o = Cv100_o[idx100_o]
chi100_o = chi100_o[idx100_o]
e100_o = e100_o[idx100_o]
absm100_o = absm100_o[idx100_o]

"""
tweak ugly data. set data that deviates much from the rest to minimum of its neighbour data
Also take average between pairs of two points from the original data (ended up not using this in the report)
"""

"""
#set to minimum of neighbour
for i in range(len(T60_o)-1):
    if np.abs(Cv60_o[i] - Cv60_o[i+1]) > 0.1:
        Cv60_o[i] = np.min([Cv60_o[i],Cv60_o[i+1]])
        absm60_o[i] = np.min([absm60_o[i],absm60_o[i+1]])

#average
for i in range(len(T60)-1):
    Cv60_o[i] = (Cv60_o[i] + Cv60_o[i+1])/2
    absm60_o[i] = (absm60_o[i] + absm60_o[i+1])/2

#set to minimum of neighbour
for i in range(len(T100_2)-1):
    if np.abs(Cv100_2[i] - Cv100_2[i+1]) > 0.1:
        Cv100_2[i] = np.min([Cv100_2[i],Cv100_2[i+1]])
        absm100_2[i] = np.min([absm100_2[i], absm100_2[i + 1]])

#average
for i in range(len(T100_2)-1):
    Cv100_2[i] = (Cv100_2[i] + Cv100_2[i+1])/2
    absm100_2[i] = (absm100_2[i] + absm100_2[i + 1]) / 2
"""


"""
plot
"""
# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
#latex font
plt.rc('text', usetex=True)
plt.rc('font', family='serif')

#heat capacity
#plt.plot(T40_o,Cv40_o,label='L = 40')
#plt.plot(T60_o,Cv60_o,label='L = 60')
#plt.plot(T80_o,Cv80_o,label='L = 80')
#plt.plot(T100_o,Cv100_o,label='L = 100')

#plt.xlabel('T  [$J/k_B$]')
#plt.ylabel('$C_V  [k_B]$')


#Magnetic susceptibility per spin
#plt.plot(T40_o,chi40_o,label='L = 40')
#plt.plot(T60_o,chi60_o,label='L = 60')
#plt.plot(T80_o,chi80_o,label='L = 80')
#plt.plot(T100_o,chi100_o,label='L = 100')

plt.xlabel('T  [$J/k_B$]')
plt.ylabel('$\chi $')

#magnetization per spin
#plt.plot(T40_o,absm40_o,label='L = 40')
#plt.plot(T60_o,absm60_o,label='L = 60')
plt.plot(T80_o,absm80_o,label='L = 80')
plt.plot(T100_o,absm100_o,label='L = 100')

plt.xlabel('T  [$J/k_B$]')
plt.ylabel('$|m|$')


plt.legend()
#plt.show()
plt.savefig("m2.pdf")