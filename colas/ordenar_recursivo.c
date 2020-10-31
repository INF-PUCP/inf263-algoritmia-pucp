#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void OrdenarRecursivo(Cola* ref_cola, int tamano) {
  if (tamano == 1) return;
  Dato minimo = Desencolar(ref_cola);
  for (int i = 0; i < tamano - 1; i++) {
    Dato actual = Desencolar(ref_cola);
    if (actual < minimo) {
      Encolar(ref_cola, minimo);
      minimo = actual;
    } else {
      Encolar(ref_cola, actual);
    }
  }
  OrdenarRecursivo(ref_cola, tamano - 1);
  Encolar(ref_cola, minimo);
}

int main(void) {
  Cola cola = NULL;

  Encolar(&cola, 2);
  Encolar(&cola, 5);
  Encolar(&cola, 3);
  Encolar(&cola, 11);
  Encolar(&cola, 7);
  Encolar(&cola, 23);
  Encolar(&cola, 19);
  
  ImprimirCola(cola);
  OrdenarRecursivo(&cola, 7);
  ImprimirCola(cola);
  return 0;
}
