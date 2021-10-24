import pyarma as pa
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

#load matrices
V = pa.cube()
R = pa.cube()
V_ex = pa.cube()
R_ex = pa.cube()
t = pa.mat()
V.load("V.bin")
R.load("R.bin")
V_ex.load("V_exchange.bin")
R_ex.load("R_exchange.bin")
t.load("t.bin")

#as array
R = np.asarray(R)
V = np.asarray(V)
R_ex = np.asarray(R_ex)
V_ex = np.asarray(V_ex)



# Figure size (inches)
figwidth = 6
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))



#plt.plot(t,R[0][:,2],label='z(t)')
#plt.plot(V[0][:,2],R[0][:,2],label='particle one')
#plt.plot(V[1][:,2],R[1][:,2],label='particle two')

#plt.plot(V_ex[0][:,2],R_ex[0][:,2],label='particle one')
#plt.plot(V_ex[1][:,2],R_ex[1][:,2],label='particle two')

#plt.xlabel('z [$\mu$ m]')
#plt.ylabel('$v_z$ [m/s]')
#plt.legend()
#plt.show()
#plt.savefig("zv_z_ex.pdf")


#3D

fig = plt.figure()
ax = fig.gca(projection='3d')
ax.set_xlabel("x")
ax.set_xlabel("y")
ax.set_xlabel("z")
ax.plot(R_ex[0][:,0], R_ex[0][:,1], R_ex[0][:,2],label='particle one')
ax.plot(R_ex[1][:,0], R_ex[1][:,1], R_ex[1][:,2],label='particle two')

#ax.plot(R[0][:,0], R[0][:,1], R[0][:,2],label='particle one')
#ax.plot(R[1][:,0], R[1][:,1], R[1][:,2],label='particle two')

#ax.plot(R[0][:,0][0], R[0][:,1][0], R[0][:,2][0],'go', label ='start')
#ax.plot(R[0][:,0][-1], R[0][:,1][-1], R[0][:,2][-1],'ro',label = 'slutt')
#ax.plot(R[1][:,0][0], R[1][:,1][0], R[1][:,2][0],'bo', label ='start')
#ax.plot(R[1][:,0][-1], R[1][:,1][-1], R[1][:,2][-1],'ro',label = 'slutt')
ax.set_xlabel('x [$\mu$ m]')
ax.set_ylabel('y [$\mu$ m]')
ax.set_zlabel('z [$\mu$ m]')
plt.legend()
#plt.show()
plt.savefig("3d_ex.pdf")



"""
#test energy

v1x = (V_ex[0][:,0])**2
v1y = (V_ex[0][:,1])**2
v1z = (V_ex[0][:,2])**2

r1x = (R_ex[0][:,0])**2
r1y = (R_ex[0][:,1])**2
r1z = (R_ex[0][:,2])**2

v2x = (V_ex[1][:,0])**2
v2y = (V_ex[1][:,1])**2
v2z = (V_ex[1][:,2])**2

r2x = (R_ex[1][:,0])**2
r2y = (R_ex[1][:,1])**2
r2z = (R_ex[1][:,2])**2

E_K1 = 0.5*(np.sqrt(v1x + v1y + v1z))
E_K2 = 0.5*(np.sqrt(v2x + v2y + v2z))

E_P1 = 0.5*(r1x + r1y + r1z)
E_P2 = 0.5*(r2x + r2y + r2z)

Etot1 = E_K1+E_P1
Etot2 = E_K2+E_P2

print(Etot1+Etot2) #external field affects the energy?
"""