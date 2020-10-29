#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void Dividir(Lista lista, Lista* par, Lista* impar) {
  Nodo* actual = lista;
  int posicion = 0;
  while (actual) {
    Dato elemento = actual->elemento;
    if (posicion & 1) {
      InsertarFinal(par, elemento);
    } else {
      InsertarFinal(impar, elemento);
    }
    actual = actual->siguiente;
    posicion++;
  }
}

int main(void) {
  Lista lista;
  CrearLista(&lista);
  
  InsertarFinal(&lista, 20);
  InsertarFinal(&lista, 19);
  InsertarFinal(&lista, 18);
  InsertarFinal(&lista, 14);
  
  Imprimir(lista);

  if (EstaEnLista(lista, 19)) {
    printf("19 esta en la lista.\n");
  } else {
    printf("19 no esta en la lista.\n");
  }

  Lista par;
  CrearLista(&par);
  
  Lista impar;
  CrearLista(&impar);
  
  Dividir(lista, &par, &impar);
  
  Imprimir(impar);
  Imprimir(par);
  return 0;
}
