all: 20185048_EX1_P01

20185048_EX1_P01: 20185048_EX1_P01.o cola.o pila.o
	gcc -o 20185048_EX1_P01 20185048_EX1_P01.o cola.o pila.o

20185048_EX1_P01.o: 20185048_EX1_P01.c cola.h pila.h nodo.h
	gcc -c 20185048_EX1_P01.c

cola.o: cola.c cola.h nodo.h
	gcc -c cola.c

pila.o: pila.c pila.h nodo.h
	gcc -c pila.c

clean:
	-rm 20185048_EX1_P01.o cola.o pila.o
