a.out: tarea7.o 
	@cc -lm tarea7.o 
	@./a.out
	@python dibujar.py
	@python periodo.py
	@rm -f *.dat

main.o: tarea7.c
	@cc -c tarea7.c


all: a.out

clean: 
	@rm -f *.o
	@rm -f a.out
	@rm -f *.jpg

