/*
 * Archivo: lista.h
 * ----------------
 * Esta interfaz exporta los metodos de una lista, una coleccion en la cual
 * se utilizan punteros para conectar todos sus nodos como los enlaces en una
 * cadena. En una lista se aloca la memoria para cada elemento en su propio
 * bloque de memoria al cual llamaremos nodo. 
 */

#ifndef _lista_h
#define _lista_h

/* Tipo de dato que se almacenara en el nodo */
typedef int Dato;

/*
 * Estructura: Nodo
 * ----------------
 * Tipo de los nodos que conformaran el cuerpo de la lista enlazada.
 * Estos son alocados en el heap. Cada nodo contiene un solo dato
 * y un puntero al siguiente nodo en la lista enlazada.
 */

typedef struct _Nodo {
  Dato elemento;
  struct _Nodo* siguiente;
} Nodo;

/* Tipo de dato para gestionar la lista enlazada */
typedef Nodo* Lista;

/*
 * Metodo: CrearLista
 * Uso: CrearLista(&lista);
 * -----------------------------
 * Asigna NULL a la lista enlazada creada.
 */

void CrearLista(Lista* lista);

/*
 * Metodo: EstaVacia
 * Uso: if (EstaVacia(lista)) . . .
 * --------------------------------
 * Retorna 1 si la lista no contiene elementos.
 */

int EstaVacia(Lista lista);

/*
 * Metodo: EstaEnLista
 * Uso: if (EstaEnLista(lista, elemento)) ...
 * ------------------------------------------
 * Retorna 1 si elemento esta en lista.
 */

int EstaEnLista(Lista lista, Dato elemento);


/*
 * Metodo: InsertarInicio
 * Uso: InsertarInicio(&lista, elemento);
 * -------------------------------------
 * Inserta el elemento especificado al inicio de la lista enlazada.
 */

void InsertarInicio(Lista* lista, Dato elemento);

/*
 * Metodo: InsertarFinal
 * Uso: InsertarFinal(&lista, elemento);
 * -------------------------------------
 * Inserta el elemento especificado al final de la lista enlazada.
 */

void InsertarFinal(Lista* lista, Dato elemento);

/*
 * Metodo: Imprimir
 * Uso: Imprimir(lista);
 * ---------------------
 * Imprime los valores de los nodos de la lista enlazada en el orden del
 * recorrido desde la cabeza de la lista hasta NULL.
 */

void Imprimir(Lista lista);

/*
 * Metodo: FinalizarLista
 * Uso: FinalizarLisa(&lista);
 * ---------------------------
 * Libera la memoria de cada nodo de la lista y asigna NULL a la lista.
 */

void FinalizarLista(Lista* lista);

/*
 * Metodo: Tamano
 * Uso: int tamano = Tamano(lista);
 * --------------------------------
 * Retorna el numero de nodos en la lista enlazada.
 */

int Tamano(Lista lista);

#endif
