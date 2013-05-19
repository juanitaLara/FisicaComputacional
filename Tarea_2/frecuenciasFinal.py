import sys, string, os, numpy


#Leer el archivo

infile = open(sys.argv[1],"r")
titulo=sys.argv[1]
texto = infile.readlines()

text=[x.lower() for x in texto]



#Guardar las letras del texto

num_lineas = len(text)

i=0
j=0
k=0

for i in range(num_lineas):
    if i==0:
        letras=list(text[i])
    else:
        letras.extend(text[i])

   
#Borrar los caracteres repetidos

letras_biblioteca=list(set(letras))
to_remove = [',', '\n', ' ', '.',';','*','"','@','/','#','%','$','[',']','(',')',':','_']

for letter in to_remove:
    letras_biblioteca.remove(letter)

num_lineas_b = len(letras_biblioteca)


#Crear un archivo con las frecuencias de cada letra


frecuencias = range(num_lineas_b)
for i in range(num_lineas_b):
    frecuencias[i] = 0

nombre_archivo= "frecuencias_"+titulo
texto_frecuencias=open(nombre_archivo,'w')

n_total = len(letras)
for j in range(num_lineas_b):
    n=letras_biblioteca[j]
    frecuencias[j]=(1.0*letras.count(n))/(1.0 * n_total)



indices_ordenados = numpy.argsort(frecuencias)

for index in indices_ordenados:
    texto_frecuencias.write("%s %f\n"%(letras_biblioteca[index], frecuencias[index]))

texto_frecuencias.close()








