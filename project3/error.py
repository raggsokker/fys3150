import pyarma as pa
import numpy as np
import matplotlib.pyplot as plt

#load matrices

#RK4

"""stepsize 0.01"""
V_RK_1 = pa.cube()
R_RK_1 = pa.cube()
t_1 = pa.mat()
V_RK_1.load("V_error_RK_01.bin")
R_RK_1.load("R_error_RK_01.bin")
t_1.load("t_01.bin")

#as array
R_RK_1 = np.asarray(R_RK_1)
V_RK_1 = np.asarray(V_RK_1)
#t_1 = np.asarray(t_1)

#got nested list. dont want that:
R_RK_1 = R_RK_1[0]
V_RK_1 = V_RK_1[0]
#t_1 = t_1[0]


"""stepsize 0.001"""
V_RK_2 = pa.cube()
R_RK_2 = pa.cube()
t_2 = pa.mat()
V_RK_2.load("V_error_RK_001.bin")
R_RK_2.load("R_error_RK_001.bin")
t_2.load("t_001.bin")

#as array
R_RK_2 = np.asarray(R_RK_2)
V_RK_2 = np.asarray(V_RK_2)
#t_2 = np.asarray(t_2)

#got nested list. dont want that:
R_RK_2 = R_RK_2[0]
V_RK_2 = V_RK_2[0]
#t_2 = t_2[0]

"""stepsize 0.0001"""

V_RK_3 = pa.cube()
R_RK_3 = pa.cube()
t_3 = pa.mat()
V_RK_3.load("V_error_RK_0001.bin")
R_RK_3.load("R_error_RK_0001.bin")
t_3.load("t_0001.bin")

#as array
R_RK_3 = np.asarray(R_RK_3)
V_RK_3 = np.asarray(V_RK_3)
#t_3 = np.asarray(t_3)

#got nested list. dont want that:
R_RK_3 = R_RK_3[0]
V_RK_3 = V_RK_3[0]
#t_3 = t_3[0]

"""stepsize 0.00005"""

V_RK_4 = pa.cube()
R_RK_4 = pa.cube()
t_4 = pa.mat()
V_RK_4.load("V_error_RK_00005.bin")
R_RK_4.load("R_error_RK_00005.bin")
t_4.load("t_00005.bin")

#as array
R_RK_4 = np.asarray(R_RK_4)
V_RK_4 = np.asarray(V_RK_4)
#t_4 = np.asarray(t_4)

#got nested list. dont want that:
R_RK_4 = R_RK_4[0]
V_RK_4 = V_RK_4[0]
#t_4 = t_4[0]

"""stepsize 0.00001"""

V_RK_5 = pa.cube()
R_RK_5 = pa.cube()
t_5 = pa.mat()
V_RK_5.load("V_error_RK_00001.bin")
R_RK_5.load("R_error_RK_00001.bin")
t_5.load("t_00001.bin")

#as array
R_RK_5 = np.asarray(R_RK_5)
V_RK_5 = np.asarray(V_RK_5)
#t_5 = np.asarray(t_5)

#got nested list. dont want that:
R_RK_5 = R_RK_5[0]
V_RK_5 = V_RK_5[0]
#t_5 = t_5[0]

#Forward Euler

"""stepsize 0.01"""
V_FE_1 = pa.cube()
R_FE_1 = pa.cube()
V_FE_1.load("V_error_FE_01.bin")
R_FE_1.load("R_error_FE_01.bin")

#as array
R_FE_1 = np.asarray(R_FE_1)
V_FE_1 = np.asarray(V_FE_1)

#got nested list. dont want that:
R_FE_1 = R_FE_1[0]
V_FE_1 = V_FE_1[0]


"""stepsize 0.001"""
V_FE_2 = pa.cube()
R_FE_2 = pa.cube()
V_FE_2.load("V_error_FE_001.bin")
R_FE_2.load("R_error_FE_001.bin")

#as array
R_FE_2 = np.asarray(R_FE_2)
V_FE_2 = np.asarray(V_FE_2)

#got nested list. dont want that:
R_FE_2 = R_FE_2[0]
V_FE_2 = V_FE_2[0]


"""stepsize 0.0001"""
V_FE_3 = pa.cube()
R_FE_3 = pa.cube()
V_FE_3.load("V_error_FE_0001.bin")
R_FE_3.load("R_error_FE_0001.bin")

#as array
R_FE_3 = np.asarray(R_FE_3)
V_FE_3 = np.asarray(V_FE_3)

#got nested list. dont want that:
R_FE_3 = R_FE_3[0]
V_FE_3 = V_FE_3[0]

"""stepsize 0.00005"""
V_FE_4 = pa.cube()
R_FE_4 = pa.cube()
V_FE_4.load("V_error_FE_00005.bin")
R_FE_4.load("R_error_FE_00005.bin")

#as array
R_FE_4 = np.asarray(R_FE_4)
V_FE_4 = np.asarray(V_FE_4)

#got nested list. dont want that:
R_FE_4 = R_FE_4[0]
V_FE_4 = V_FE_4[0]

"""stepsize 0.00001"""
V_FE_5 = pa.cube()
R_FE_5 = pa.cube()
V_FE_5.load("V_error_FE_00001.bin")
R_FE_5.load("R_error_FE_00001.bin")

#as array
R_FE_5 = np.asarray(R_FE_5)
V_FE_5 = np.asarray(V_FE_5)

#got nested list. dont want that:
R_FE_5 = R_FE_5[0]
V_FE_5 = V_FE_5[0]

""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#gather stuff in array

R_RK = np.array([R_RK_1,R_RK_2,R_RK_3,R_RK_4,R_RK_5],dtype=object)
R_FE = np.array([R_FE_1,R_FE_2,R_FE_3,R_FE_4,R_FE_5],dtype=object)
t = np.array([t_1,t_2,t_3,t_4,t_5],dtype=object)
h = np.array([0.01,0.001,0.0001,0.00005,0.00001]) #stepsizes

#values

q = 2 #e
m = 40.078 #atomic mass u
B0 = 9.65e1 #u/(mu s*e)
V0 = 9.65e8 #u*(mu m)^2/((mu s)^2*e)
d = 1e4 #mu m

omega_0 = q*B0/m
omega_z_squared = 2*q*V0/(m*d**2)

#A_+ and A_-

def A(v0,x0,omega_0,omega_z_squared):
    omega_plus = (omega_0 + np.sqrt(omega_0**2 - 2*omega_z_squared))/2
    omega_minus = (omega_0 - np.sqrt(omega_0**2 - 2*omega_z_squared))/2
    A_plus = (v0 + omega_minus*x0)/(omega_minus - omega_plus)
    A_minus = -(v0 + omega_plus*x0)/(omega_minus - omega_plus)
    return A_plus,A_minus,omega_plus,omega_minus

#analytic expression

def f(v0,x0,z0,omega_0,omega_z_squared,t):
    A_plus,A_minus,omega_plus,omega_minus = A(v0,x0,omega_0,omega_z_squared)

    x = A_plus*np.cos(omega_plus*t) + A_minus*np.cos(omega_minus*t)
    y = -A_plus*np.sin(omega_plus*t) - A_minus*np.sin(omega_minus*t)
    z = z0*np.cos(np.sqrt(omega_z_squared)*t)
    array = np.array([x,y,z])
    return np.hstack(array)

print(np.sqrt(omega_z_squared))

def plot_rel_error(v0,x0,z0,omega_0,omega_z_squared,t,R,h):
    n = len(R)
    f_ana = f(v0, x0, z0, omega_0, omega_z_squared, t)
    f_num = R

    norm_f_ana = np.linalg.norm(f_ana,axis=1)
    norm_f_num = np.linalg.norm(f_num,axis=1)
    rel_error = np.abs(norm_f_ana - norm_f_num) / norm_f_ana
    plt.plot(t,rel_error,label=f'$h = {h}$')



x0 = 150
z0 = 150
v0 = 100


#plot
#f = f(v0, x0, z0, omega_0, omega_z_squared, t[-3])
#plt.plot(t[-3],f[:,2],label='ana')
#plt.plot(t[-3],R_RK[-3][:,2],label='num')
#plt.legend()
#plt.show()


#RK4

#for i in range(len(t)):
#    plot_rel_error(v0, x0, z0, omega_0, omega_z_squared, t[i], R_RK[i], h[i])

#Forward Euler

#for i in range(1,len(t)):
#    plot_rel_error(v0, x0, z0, omega_0, omega_z_squared, t[i], R_FE[i], h[i])

#plt.legend()
#plt.xlabel('t [$\mu$ s]')
#plt.ylabel('Relative error')
#plt.legend()
#plt.show()
#plt.savefig("error_FE_2.pdf")


"""
error convergence rate
"""
def r_err(R):
    r_err = 0
    for i in range(2, len(h)):
        f_ana_k = f(v0, x0, z0, omega_0, omega_z_squared, t[i])
        f_num_k = R[i]
        norm_f_ana_k = np.linalg.norm(f_ana_k, axis=1)
        norm_f_num_k = np.linalg.norm(f_num_k, axis=1)

        f_ana_k_back = f(v0, x0, z0, omega_0, omega_z_squared, t[i - 1])
        f_num_k_back = R[i - 1]
        norm_f_ana_k_back = np.linalg.norm(f_ana_k_back, axis=1)
        norm_f_num_k_back = np.linalg.norm(f_num_k_back, axis=1)

        delta_max_k = np.max(np.abs(norm_f_ana_k - norm_f_num_k))
        delta_max_k_back = np.max(np.abs(norm_f_ana_k_back - norm_f_num_k_back))

        r_err += (1 / 4) * np.log(delta_max_k / delta_max_k_back) / np.log(h[i] / h[i - 1])
    return r_err


r_err_RK = r_err(R_RK)
r_err_FE = r_err(R_FE)

print(r_err_RK)
print(r_err_FE)
