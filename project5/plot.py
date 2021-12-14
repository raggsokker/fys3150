import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm



#load matrices

U_single_slit = pa.cx_cube()
U_single_slit.load("U_single_slit.bin")
U_double_slit = pa.cx_cube()
U_double_slit.load("U_double_slit2.bin")
U_triple_slit = pa.cx_cube()
U_triple_slit.load("U_triple_slit.bin")

#make as array and compute probability from real and imaginary part
U_single_slit = np.asarray(U_single_slit)
P_single_slit = np.conj(U_single_slit) * U_single_slit
U_double_slit = np.asarray(U_double_slit)
P_double_slit = np.conj(U_double_slit) * U_double_slit
U_triple_slit = np.asarray(U_triple_slit)
P_triple_slit = np.conj(U_triple_slit) * U_triple_slit
#make P as real dtype
P_single_slit = P_single_slit.real
P_double_slit = P_double_slit.real
P_triple_slit = P_triple_slit.real



"""
Plot
"""

# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))
#latex font
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
font = {'size': 14}
plt.rc('font', **font)

"""
Marginalized plots
"""

#make y array
ymax = 1
h = 0.005
N = int(ymax/h)
y = np.linspace(0,ymax,N)

#normalize margin
margin_single_slit = []
s_single_slit = 0
margin_double_slit = []
s_double_slit = 0
margin_triple_slit = []
s_triple_slit = 0
for i in range(len(P_double_slit[0][:,0])):
    s_single_slit += P_single_slit[79][160][i]
    s_double_slit += P_double_slit[79][160][i]
    s_triple_slit += P_triple_slit[79][160][i]

for i in range(len(P_double_slit[0][:,0])):
    margin_single_slit.append(P_single_slit[79][160][i] / s_single_slit)
    margin_double_slit.append(P_double_slit[79][160][i] / s_double_slit)
    margin_triple_slit.append(P_triple_slit[79][160][i] / s_triple_slit)

#plt.plot(y, margin_single_slit,label='Single slit')
#plt.plot(y, margin_double_slit,label='Double slit')
#plt.plot(y, margin_triple_slit,label='Triple slit')
#plt.legend()
#plt.xlabel('y')
#plt.ylabel('P(y$|$x=0.8;t=0.002)')
#plt.savefig("Margin.pdf")
#plt.show()




"""
Imshow plots
"""


#probability
#plt.imshow(np.sqrt(P_double_slit[0]),extent=[0,1,1,0])
#plt.imshow(np.sqrt(P_double_slit[39]),extent=[0,1,1,0])
#plt.imshow(np.sqrt(P_double_slit[79]),extent=[0,1,1,0])
##real(U)
#plt.imshow(np.real(U_double_slit[0]),extent=[0,1,1,0])
#plt.imshow(np.real(U_double_slit[39]),extent=[0,1,1,0])
#plt.imshow(np.real(U_double_slit[79]),extent=[0,1,1,0])
##imag(U)
#plt.imshow(np.imag(U_double_slit[0]),extent=[0,1,1,0])
#plt.imshow(np.imag(U_double_slit[39]),extent=[0,1,1,0])
plt.imshow(np.imag(U_double_slit[79]),extent=[0,1,1,0])
plt.colorbar()
#plt.text(0.4, -0.07, 'Im(u(t = 0.002))', bbox={'facecolor': 'white', 'edgecolor':'none', 'pad': 5})
#80,-10

plt.xlabel('y')
plt.ylabel('x')
plt.show()
#plt.savefig("Im(u(0.002)).pdf")
