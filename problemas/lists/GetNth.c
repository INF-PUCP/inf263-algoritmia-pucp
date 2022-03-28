#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* 
 * Given a list and an index, return the data
 * in the nth node of the list. The nodes are numbered from 0.
 * Assert fails if the index is invalid (outside 0..lengh-1).
 */

Dato GetNth(Lista lista, int indice) {
  assert(indice < Tamano(lista));
  Nodo* actual = lista;
  int indice_actual = 0;
  while (indice_actual < indice) {
    actual = actual->siguiente;
    indice_actual++;
  }
  return actual->elemento;
}

int main(void) {
  Lista lista;
  CrearLista(&lista);

  InsertarFinal(&lista, 42);
  InsertarFinal(&lista, 13);
  InsertarFinal(&lista, 666);

  Imprimir(lista);

  assert(GetNth(lista, 0) == 42);
  assert(GetNth(lista, 1) == 13);
  assert(GetNth(lista, 2) == 666);

  printf("Todos los casos estan OK\n");
  return 0;
}
