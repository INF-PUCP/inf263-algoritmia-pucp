#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila.h"

void CrearPila(Pila* ref_pila) {
  *ref_pila = NULL;
}

int EsPilaVacia(Pila pila) {
  return (pila == NULL);
}

void Imprimir(Pila pila) {
  Nodo* actual = pila;
  while (actual != NULL) {
    printf("%d ", actual->elemento);
    actual = actual->siguiente;
  }
  printf("\n");
}

void Push(Pila* ref_pila, Dato valor) {
  Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
  nuevo->elemento = valor;
  nuevo->siguiente = *ref_pila;
  *ref_pila = nuevo;
}

Dato Pop(Pila* ref_pila) {
  //assert(!EstaVacia(*ref_pila));
  Dato valor = -1;
  Nodo* liberar = *ref_pila;
  if (!EsPilaVacia(liberar)) {
    valor = liberar->elemento;
    *ref_pila = liberar->siguiente;
    free(liberar);
  }
  return valor;
}

Dato Top(Pila pila) {
  //assert(!EstaVacia(pila));
  Dato valor = -1;
  if (!EsPilaVacia(pila)) return pila->elemento;
  return valor;
}

int Tamano(Pila pila) {
  int cnt = 0;
  Nodo* actual = pila;
  while (actual != NULL) {
    cnt++;
    actual = actual->siguiente;
  }
  return cnt;
}
