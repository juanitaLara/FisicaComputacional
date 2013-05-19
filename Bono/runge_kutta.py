import sys, string, os, numpy


G = 6.67384E-11
M = 1.989E42

n_points = 1000
h = 2000000000/n_points

datos = numpy.loadtxt('vel.dat')


def func_1(t,r_1):
    return r_1

def func_2(t,r_1,r_2):
    return -G*M/(r_1*r_1)

def runge_kutta(h, t, r_1, r_2):
   
    k1_1 = func_1(t,r_2)
    k1_2 = func_2(t,r_1,r_2)

    t1 = t + (h/2)
    r1_1 = r_1 + (h/2.0)*k1_1
    r1_2 = r_2 + (h/2.0)*k1_2

    k2_1 = func_1(t1, )



r = datos [:,0]





