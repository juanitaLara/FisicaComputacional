import string
import numpy
import scipy
from pylab import *
from scipy.optimize import curve_fit
from scipy.linalg import *

dibujar = numpy.loadtxt('Data.dat')
t = dibujar[:,0]
r = dibujar[:,1]
v = dibujar[:,2]
p = dibujar[:,3]

max=[];
medioR=[];
for i in range(numpy.size(r)-1):
    if(r[i]>r[i-1]):
        if(r[i]>r[i+1]):
            max.append(t[i])
            medioR.append(r[i])

size=numpy.size(max)-1
menor=max[size-1]
mayor=max[size]
mayorM=medioR[size]
periodo = (mayor - menor)/(3600*24.0)


medio=[];
i=size;
para = True;
while para:
    if(r[i]<r[i-1]):
        if(r[i]<r[i+1]):
            medio.append(r[i])
            para=False
    i=i-1

sizeM=numpy.size(medio)-1
menorM=medio[sizeM]
media = (mayorM + menorM)/2

data=open('period_amplitude.txt','w')
data.write('El periodo de oscilacion es: '+ str(periodo) + ' Dias\n')
data.write('Radio promedio : '+ str(media) + ' cm \n')
data.close()