#include <stdio.h>
#include <stdlib.h>

/* Tipo de dato que se almacenara en el nodo */
typedef int Dato;

typedef struct TNodo {
  Dato elemento;
  struct TNodo* siguiente;
} Nodo;

/* Tipo de dato para gestionar la lista enlazada */
typedef Nodo* Lista;

/* Prototipos del tipo de dato Lista */
void CrearLista(Lista* lista);

int EstaVacia(Lista lista);

int EstaEnLista(Lista lista, Dato elemento);

void InsertarInicio(Lista* lista, Dato elemento);

void InsertarFinal(Lista* lista, Dato elemento);

void Imprimir(Lista lista);

void FinalizarLista(Lista lista);

int Tamano(Lista lista);
