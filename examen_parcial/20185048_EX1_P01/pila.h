/*
 * Archivo: pila.h
 * ---------------
 * Esta interfaz exporta los metodos de una pila, la cual es una coleccion de
 * elementos que procesan valores en el orden last-in / first-out (LIFO).
 */

#ifndef _pila_h
#define _pila_h

typedef Nodo* Pila;

/*
 * Metodo: CrearPila
 * Uso: CrearPila(&pila);
 * ----------------------
 * Inicializa una nueva pila vacia en NULL.
 */

void CrearPila(Pila* ref_pila);

/*
 * Metodo: EstaVacia
 * Uso: if (EstaVacia(pila)) . . .
 * -------------------------------
 * Retorna 1 si la pila no contiene elementos.
 */

int EsPilaVacia(Pila pila);

/*
 * Metodo: Finalizar
 * Uso: Finalizar(&pila);
 * ----------------------
 * Elimina todos los elementos de la pila.
 */

void Finalizar(Pila* ref_pila);

/*
 * Metodo: Imprimir
 * Uso: Imprimir(pila);
 * --------------------
 * Imprime los valores de la pila desde el ultimo hasta el primero.
 */

void Imprimir(Pila pila);

/*
 * Metodo: Push
 * Uso: Push(&pila, valor);
 * ------------------------
 * Anade el valor especificado en la pila.
 */

void Push(Pila* pila, Dato valor);

/*
 * Metodo: Pop
 * Uso: Dato ultimo = Pop(&pila);
 * ------------------------------
 * Elimina el elemento en la cima de la pila y lo retorna.
 * Este metodo indica un error si es llamado en una pila vacia.
 */

Dato Pop(Pila* ref_pila);

/*
 * Metodo: Top
 * Uso: Dato cima = Top(pila);
 * ---------------------------
 * Retorna el valor del elemento en la cima de la pila sin eliminarlo.
 * Este metodo indica un error si es llamado en una pila vacia.
 */

Dato Top(Pila pila);

/*
 * Metodo: Tamano
 * Uso: int tamano = Tamano(pila);
 * -------------------------------
 * Retorna el numero de elementos en esta pila.
 */

int Tamano(Pila pila);

#endif
