all: main

main: main.o pila.o
	gcc -o main main.o pila.o

main.o: main.c pila.h
	gcc -c main.c

pila.o: pila.c pila.h
	gcc -c pila.c

clean:
	-rm main.o pila.o
