#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void Revertir(Lista* lista) {
  Nodo* anterior = NULL;
  Nodo* actual = *lista;
  Nodo* auxiliar = NULL;
  while (actual) {
    auxiliar = actual->siguiente;
    actual->siguiente = anterior;
    anterior = actual;
    actual = auxiliar;
  }
  *lista = anterior;
}

int main(void) {
  Lista lista;
  CrearLista(&lista);
  
  InsertarFinal(&lista, 1);
  InsertarFinal(&lista, 2);
  InsertarFinal(&lista, 3);
  InsertarFinal(&lista, 4);

  Imprimir(lista);
  Revertir(&lista);
  Imprimir(lista);
  return 0;
}
