import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt



#load matrices

U_zero_potential = pa.cx_cube()
U_double_slit = pa.cx_cube()
U_zero_potential.load("U_zero_potential.bin")
U_double_slit.load("U_double_slit.bin")

#make as array and compute probability from real and imaginary part
U_zero_potential = np.asarray(U_zero_potential)
P_zero_potential = np.conj(U_zero_potential)*U_zero_potential

U_double_slit = np.asarray(U_double_slit)
P_double_slit = np.conj(U_double_slit)*U_double_slit
#make it as real dtype
P_zero_potential = P_zero_potential.real
P_double_slit = P_double_slit.real

#make deviation from 1 arrays
deviation_zero_potential = []
deviation_double_slit = []

for i in range(len(P_double_slit[:,0])):
    deviation_zero_potential.append(1-np.sum(P_zero_potential[i]))
    deviation_double_slit.append(1-np.sum(P_double_slit[i]))


# Array of time points
dt = 2.5e-5;
T = 0.008;
N_t = int(T/dt)
t = np.linspace(0,T,N_t)

#plot

# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
#latex font
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
font = {'size': 14}
plt.rc('font', **font)


plt.plot(t[::5],np.abs(deviation_zero_potential[::5]),'x',label='zero potential')
plt.plot(t[::5],np.abs(deviation_double_slit[::5]),'x',label='double slit potential')
plt.legend()
plt.xlabel('time')
plt.ylabel('deviation from 1')
plt.savefig("deviation.pdf")
#plt.show()



