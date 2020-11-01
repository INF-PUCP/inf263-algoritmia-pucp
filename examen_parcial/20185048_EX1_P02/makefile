all: 20185048_EX1_P02

20185048_EX1_P02: 20185048_EX1_P02.o pila.o
	gcc -o 20185048_EX1_P02 20185048_EX1_P02.o pila.o

20185048_EX1_P02.o: 20185048_EX1_P02.c pila.h
	gcc -c 20185048_EX1_P02.c

pilas.o: pila.c pila.h
	gcc -c pila.c

clean:
	-rm 20185048_EX1_P02.o pila.o
