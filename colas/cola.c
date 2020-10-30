#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void CrearCola(Cola* ref_cola) {
  *ref_cola = NULL;
}

int EstaVacia(Cola cola) {
  return (cola == NULL);
}

void Encolar(Cola* ref_cola, Dato valor) {
  Nodo* ultimo = (Nodo*) malloc(sizeof(Nodo));
  ultimo->elemento = valor;
  ultimo->siguiente = *ref_cola;
  *ref_cola = ultimo;
}

Dato Desencolar(Cola* ref_cola) {
  assert(!EstaVacia(*ref_cola));
  Nodo* anterior = NULL;
  Nodo* actual = *ref_cola;
  if (!EstaVacia(actual)) {
    while (actual->siguiente != NULL) {
      anterior = actual;
      actual = actual->siguiente;
    }
    if (anterior != NULL) {
      anterior->siguiente = NULL;
    } else {
      *ref_cola = NULL;
    }
    Dato valor = actual->elemento;
    free(actual);
    return valor;
  }
}

void ImprimirCola(Cola cola) {
  Nodo* actual = cola;
  while (actual != NULL) {
    printf("%d -> ", actual->elemento);
    actual = actual->siguiente;
  }
  printf("NULL\n");
}
