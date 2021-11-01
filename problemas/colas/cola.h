/*
 * Archivo: cola.h
 * ---------------
 * Esta interfaz exporta los metodos de una cola, una coleccion en la
 * cual sus valores son procesados en el orden first-in / first-out (FIFO).
 */

#ifndef _cola_h
#define _cola_h

typedef int Dato;

typedef struct _Nodo {
  Dato elemento;
  struct _Nodo* siguiente;
} Nodo;

typedef Nodo* Cola;

/*
 * Metodo: CrearCola
 * Uso: CreaCola(&cola);
 * ---------------------
 * Inicializa una cola vacia en NULL.
 */

void CrearCola(Cola* ref_cola);

/*
 * Metodo: EstaVacia
 * Uso: if (EstaVacia(cola)) . . .
 * -------------------------------
 * Retorna 1 si la cola no contiene elementos.
 */

int EstaVacia(Cola cola);

/*
 * Metodo: Encolar
 * Uso: Encolar(&cola, valor);
 * ---------------------------
 * Anade el valor especificado al final de la cola.
 */

void Encolar(Cola* ref_cola, Dato valor);

/*
 * Metodo: Desencolar
 * Uso: Dato primero = Desencolar(&cola);
 * --------------------------------------
 * Elimina y retorna el primer elemento en la cola.
 */

Dato Desencolar(Cola* ref_cola);

/*
 * Metodo: ImprimirCola
 * Uso: ImprimirCola(cola);
 * ------------------------
 * Imprime la cola desde el ultimo elemento hasta el primero.
 */

void ImprimirCola(Cola cola);

#endif
