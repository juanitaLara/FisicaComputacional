#ejecuta funciones descritas 
a.out: tarea6.o runge.o funcion.o
	@cc -lm tarea6.o runge.o funcion.o
	@./a.out
	@python dibujar.py
	
#segmento de ejecucion 
main.o: tarea6.c
	@cc -c tarea6.c

runge.o: runge.c
	@cc -c runge.c

funcion.o: funcion.c
	@cc -c funcion.c

all: a.out

clean: 
	@rm -f *.o
	@rm -f a.out
	@rm -f *.pdf

