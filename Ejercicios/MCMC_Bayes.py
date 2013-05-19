import math
import sys
import string
import cmath
import numpy as np
import matplotlib.pyplot as plt

obs_data = np.loadtxt("traces.dat")
x_1_obs = obs_data[:,0]
y_1_obs = obs_data[:,1]
z_1_obs = obs_data[:,2]
x_2_obs = obs_data[:,3]
y_2_obs = obs_data[:,4]
z_2_obs = obs_data[:,5]


def likelihood(x_obs, x_model, y_obs, y_model):
    chi_squared = ((y_obs-y_model)**2 + (x_obs-x_model)**2)
    return -chi_squared

def my_model_x(x_1_obs, z_1_obs, z_2_obs, x_rand, z_rand):
    m1 = (x_1_obs-x_rand)/(z_1_obs-z_rand)
    x = m1*(z_1_obs+z_2obs)

    return x

def my_model_y(y_1_obs, z_1_obs, z_2_obs, y_rand, z_rand):
    m2 = (y_1_obs-y_rand)/(z_1_obs-z_rand)
    y = m2*(z_1_obs+z_2obs)

    return y

#List to keep the steps

x_walk = np.empty((0))
y_walk = np.empty((0))
z_walk = np.empty((0))

x_walk = np.append(x_walk, np.random.random())
y_walk = np.append(y_walk, np.random.random())
z_walk = np.append(z_walk, -np.random.random())


n_iterations = 200000

for i in range(n_iterations):
    x_p = np.random.normal(x_walk[i], 1.0)
    y_p = np.random.normal(y_walk[i], 1.0)
    z_p = np.random.normal(z_walk[i], 1.0)
    
    x_init = my_model_x(x_1_obs, z_1_obs, z_2_obs, x_walk[i], z_walk[i])
    y_init = my_model_y(y_1_obs, z_1_obs, z_2_obs, y_walk[i], z_walk[i])
    x_prime = my_model(x_1_obs, z_1_obs, z_2_obs, x_p, z_p)
    y_prime = my_model(x_1_obs, z_1_obs, z_2_obs, y_p, z_p)

    alpha = likelihood(x_obs_2, y_obs_2, x_prime, y_prime)/likelihood(x_obs_2, y_obs_2, x_init, y_init)


    if(alpha<=1.0):
        x_walk = np.append(x_walk, x_p)
        y_walk = np.append(y_walk, y_p)
        c_walk = np.append(z_walk, z_p)
    else:

        beta = np.random.random()
        if(beta<=exp(-alpha)):
            x_walk = np.append(x_walk, x_p)
            y_walk = np.append(y_walk, y_p)
            z_walk = np.append(z_walk, z_p)
        else:
            x_walk = np.append(x_walk, x_walk[i])
            y_walk = np.append(y_walk, y_walk[i])
            z_walk = np.append(z_walk, z_walk[i])


average_a = np.average(a_walk)
average_b = np.average(b_walk)
average_c = np.average(c_walk)

best_y = my_model(x_obs, average_a, average_b, average_c)
plt.scatter(x_obs, y_obs)
plt.plot(x_obs, best_y)

plt.show()

