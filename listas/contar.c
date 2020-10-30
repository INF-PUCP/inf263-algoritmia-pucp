#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
 * Given a list and an int, return the number of times that Data occurs
 * in the list.
 */

int Contar(Lista lista, Dato objetivo) {
  int cnt = 0;
  Nodo* actual = lista;
  while (actual != NULL) {
    if (actual->elemento == objetivo) cnt++;
    actual = actual->siguiente;
  }
  return cnt;
}

int main(void) {
  Lista lista;
  CrearLista(&lista);

  InsertarFinal(&lista, 2);
  InsertarFinal(&lista, 3);
  InsertarInicio(&lista, 1);
  InsertarFinal(&lista, 1);

  Imprimir(lista);

  assert(Contar(lista, 1) == 2);
  assert(Contar(lista, 2) == 1);
  assert(Contar(lista, 3) == 1);

  printf("Todos los casos estan OK.\n");
  return 0;
}
