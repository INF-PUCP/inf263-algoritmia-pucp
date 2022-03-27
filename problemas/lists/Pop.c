#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* 
 * The opposite of Push(). Takes a non-empty list and removes the front node,
 * and returns the data which was in that node.
 */

Dato Pop(Lista* lista) {
  Nodo* cabeza = *lista;
  assert(!EstaVacia(cabeza));

  Dato resultado = cabeza->elemento;
  *lista = cabeza->siguiente;
  free(cabeza);
  return resultado;
}

int main(void) {
  Lista cabeza = NULL;
  InsertarFinal(&cabeza, 1);
  InsertarFinal(&cabeza, 2);
  InsertarFinal(&cabeza, 3);
  Imprimir(cabeza);

  assert(Pop(&cabeza) == 1);
  Imprimir(cabeza);

  assert(Pop(&cabeza) == 2);
  Imprimir(cabeza);

  assert(Pop(&cabeza) == 3);
  Imprimir(cabeza);

  printf("Todos los casos estan OK.\n");
  return 0;
}
