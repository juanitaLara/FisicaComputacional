import string
import numpy
import scipy
from pylab import *
from scipy.optimize import curve_fit
from scipy.linalg import *

#prepara los archivos uno a uno para ser leidos
dibujar = numpy.loadtxt('Data.dat')
t = dibujar[:,0]
r = dibujar[:,1]
v = dibujar[:,2]
p = dibujar[:,3]
    
#grafica t vs r
plot(t, r)
xlabel('t')
ylabel('R')
title('t vs R')
savefig('Plano_t,R.pdf')
close()
    
#grafica t vs v
plot(t, v)
xlabel('t')
ylabel('V')
title('Plano_t,V')
savefig('Plano_t,V.pdf')
close()
    
#grafica t vs p
plot(t, p)
xlabel('t')
ylabel('P')
title('Plano_t,P')
savefig('Plano_t,P.pdf')
close()


