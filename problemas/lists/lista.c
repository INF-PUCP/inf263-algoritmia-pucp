#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void CrearLista(Lista* lista) {
  *lista = NULL;
}

int EstaVacia(Lista lista) {
  return (lista == NULL);
}

int EstaEnLista(Lista lista, Dato elemento) {
  Nodo* actual = lista;
  while (actual != NULL) {
    if (actual->elemento == elemento) return 1;
    actual = actual->siguiente;
  }
  return 0;
}

void InsertarInicio(Lista* lista, Dato elemento) {
  Nodo* nuevo;
  nuevo = (Nodo*) malloc(sizeof(Nodo));
  nuevo->elemento = elemento;
  nuevo->siguiente = *lista;
  *lista = nuevo;
}

void InsertarFinal(Lista* lista, Dato elemento) {
  Nodo* nuevo;
  nuevo = (Nodo*) malloc(sizeof(Nodo));
  nuevo->elemento = elemento;
  nuevo->siguiente = NULL;

  Nodo* actual = *lista;
  Nodo* anterior = NULL;
  while (actual != NULL) {
    anterior = actual;
    actual = actual->siguiente;
  }
  if (anterior != NULL) {
    anterior->siguiente = nuevo;
  } else {
    *lista = nuevo;
  }
}

void Imprimir(Lista lista) {
  Nodo* actual;
  actual = lista;
  while (actual != NULL) {
    printf("%d -> ", actual->elemento);
    actual = actual->siguiente;
  }
  printf("NULL\n");
}

void FinalizarLista(Lista* lista) {
  Nodo* actual = *lista;
  Nodo* liberar;
  while (actual != NULL) {
    liberar = actual;
    actual = actual->siguiente;
    free(liberar);
  }
  *lista = NULL;
}

int Tamano(Lista lista) {
  Nodo* actual = lista;
  int cnt = 0;
  while (actual != NULL) {
    cnt++;
    actual = actual->siguiente;
  }
  return cnt;
}
