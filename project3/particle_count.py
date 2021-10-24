import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt

#load matrices
P_f1 = pa.mat()
P_f2 = pa.mat()
P_f3 = pa.mat()
P_f1_fine = pa.mat()
P_f2_fine = pa.mat()
P_f3_fine = pa.mat()
P_f1_fine_exchange = pa.mat()
omega_V = pa.mat()
omega_V_fine = pa.mat()
P_f1.load("P_f1.bin")
P_f2.load("P_f2.bin")
P_f3.load("P_f3.bin")
P_f1_fine.load("P_f1_fine.bin")
P_f2_fine.load("P_f2_fine.bin")
P_f3_fine.load("P_f3_fine.bin")
P_f1_fine_exchange.load("P_f1_fine_exchange.bin")
omega_V.load("omega_V.bin")
omega_V_fine.load("omega_V_fine.bin")


# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))


#plt.plot(omega_V,P_f1,label='f = 0.1')
#plt.plot(omega_V,P_f2,label='f = 0.4')
#plt.plot(omega_V,P_f3,label='f = 0.7')
#plt.plot(omega_V_fine,P_f1_fine,label='f = 0.1')
#plt.plot(omega_V_fine,P_f2_fine,label='f = 0.4')
#plt.plot(omega_V_fine,P_f3_fine,label='f = 0.7')
plt.plot(omega_V_fine,P_f1_fine_exchange,label='f = 0.1')

plt.xlabel('$\omega_V [M Hz]$')
plt.ylabel('particles trapped after 500 $\mu$s')
plt.legend()
#plt.show()
plt.savefig("trapped_ex.pdf")


