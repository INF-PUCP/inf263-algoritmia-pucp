#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void Pasar(Pila* ref_pila_1, Pila* ref_pila_2) {
  if (EstaVacia(*ref_pila_1)) return;
  Dato cima = Pop(ref_pila_1);
  Pasar(ref_pila_1, ref_pila_2);
  Push(ref_pila_2, cima);
}

int main(void) {
  Pila pila1 = NULL;
  Pila pila2 = NULL;

  Push(&pila1, 1);
  Push(&pila1, 2);
  Push(&pila1, 3);
  Push(&pila1, 4);
  Push(&pila1, 5);

  Imprimir(pila1);
  Imprimir(pila2);

  Pasar(&pila1, &pila2);

  Imprimir(pila1);
  Imprimir(pila2);
  return 0;
}
