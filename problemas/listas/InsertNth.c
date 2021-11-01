#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* A more general version of Push().
 * Given a list, an index 'n' in the range 0..length,
 * and a data element, add a new node to the list so
 *  that it has the given index.
 */
void InsertNth(Lista* ref_cabeza, int indice, Dato dato) {
  Nodo* actual = *ref_cabeza;
  assert(indice <= Tamano(actual));

  if (indice == 0) {
    InsertarInicio(ref_cabeza, dato);
  } else {
    Nodo* anterior = NULL;
    int indice_actual = 0;
    while (indice_actual < indice) {
      anterior = actual;
      actual = actual->siguiente;
      indice_actual++;
    }
    Nodo* nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
    nuevo_nodo->elemento = dato;
    nuevo_nodo->siguiente = actual;
    anterior->siguiente = nuevo_nodo;
  }
}
int main(void) {
  Lista cabeza = NULL;
  InsertNth(&cabeza, 0, 13);
  Imprimir(cabeza);
  InsertNth(&cabeza, 1, 42);
  Imprimir(cabeza);
  InsertNth(&cabeza, 1, 5);
  Imprimir(cabeza);
  return 0;
}
