#include "lista.h"

void CrearLista(Lista* lista) {
  *lista = NULL;
}

int EstaVacia(Lista lista) {
  return (lista == NULL);
}

int EstaEnLista(Lista lista, Dato elemento) {
  Nodo* actual = lista;
  while (actual) {
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
  while (actual) {
    anterior = actual;
    actual = actual->siguiente;
  }
  if (anterior) {
    anterior->siguiente = nuevo;
  } else {
    *lista = nuevo;
  }
}

void Imprimir(Lista lista) {
  Nodo* actual;
  actual = lista;
  while (actual) {
    printf("%d -> ", actual->elemento);
    actual = actual->siguiente;
  }
  printf("NULL\n");
}

void Finalizar(Lista lista) {
  Nodo* actual = lista;
  Nodo* liberar;
  while (actual) {
    liberar = actual;
    actual = actual->siguiente;
    free(liberar);
  }
}

int Tamano(Lista lista) {
  Nodo* actual = lista;
  int cnt = 0;
  while (actual) {
    cnt++;
    actual = actual->siguiente;
  }
  return cnt;
}
