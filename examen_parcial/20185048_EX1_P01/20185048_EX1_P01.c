#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cola.h"
#include "pila.h"

/* 
 * Primero creare mis funciones para manipular el hash.
 * Por cuestion de simplicidad, asumire que la cantidad de productos es menor que 100.
 *
 * Lotes: 0 (A), 1 (B), 2 (C)
 * Codigo: numero natural
 * Cantidad: numero natural < 100
 */

int ObtenerHash(int lote, int codigo, int cantidad) {
  return (1000 * lote + 100 * codigo + cantidad);
}

char ObtenerLote(int hash) {
  return (char) ('A' + hash / 1000);
}

int ObtenerCodigo(int hash) {
  int resto = hash / 100;
  return (resto % 10);
}

char ObtenerCantidad(int hash) {
  return (hash % 100);
}

void ImprimirProductos(Cola cola) {
  int primera_vez = 1;
	while (cola != NULL){
    if (primera_vez) {
      primera_vez = 0;
    } else {
      printf(" -> ");
    }
    int hash = cola->elemento;
		printf("%c%d", ObtenerLote(hash), ObtenerCodigo(hash));
    cola = cola->siguiente;
  }
  printf("\n");
}

int main(void) {
  /* Lectura de datos */
  printf("Ingrese la cantidad de productos: ");
  int cantidad_productos;
  scanf("%d", &cantidad_productos);

  /*
   * Esta cola almacenara los datos originales y, como esta descrito en el
   * enunciado, estan ordenados por lote, y si son del mismo lote, por calidad
   */
  
  Cola cola_original;
  CrearCola(&cola_original);
  int tipo_lote, codigo_producto, cantidad_actual;
  for (int i = 0; i < cantidad_productos; i++) {
    printf("Ingrese el tipo de lote como entero (A = 0, B = 1, C = 2): ");
    scanf("%d", &tipo_lote);
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &codigo_producto);
    printf("Ingrese la cantidad de productos con este lote y codigo: ");
    scanf("%d", &cantidad_actual);
    /* Encolo el hash de los datos recibidos */
    Encolar(&cola_original, ObtenerHash(tipo_lote, codigo_producto, cantidad_actual));
  }

  /* Imprimo la cola original */
  ImprimirProductos(cola_original);

  /* 
   * Esta nueva cola tendra la respuesta final, la cual consiste en eliminar
   * los productos del lote C, y ordenar los nuevos productos de acuerdo al
   * codigo ya que los lotes A y B son considerados de la misma calidad.
   */

  Cola nueva_cola;
  CrearCola(&nueva_cola);
  
  /* En esta pila guardare los productos del tipo A. */
  Pila pila_a;
  CrearPila(&pila_a);
  
  /* Variable que usare para saber cuantos elementos del tipo B hay. */
  int cantidad_b = 0;
  
  /*
   * Primero, voy desencolando elementos, si es que son del lote A, entonces
   * los apilo. Si son del lote B, lo encolo en la original, y si son del
   * lote C, simplemente los ignoro.
   */

  for (int i = 0; i < cantidad_productos; i++) {
    int primero = Desencolar(&cola_original);
    char lote_actual = ObtenerLote(primero);
    if (lote_actual == 'A') {
      Push(&pila_a, primero);
    } else {
      if (lote_actual == 'B') {
        Encolar(&cola_original, primero);
        cantidad_b++;
      }
    }
  }

  /*
   * Luego, invertire la pila antes de realizar la fusion. No estoy usando memoria
   * extra porque cada vez que creo un nodo en mi pila auxiliar, estoy limpiando
   * el espacio de memoria de la pila con los productos del lote A.
   */

  Pila auxiliar;
  CrearPila(&auxiliar);
  while (!EsPilaVacia(pila_a)) {
    int cima = Top(pila_a);
    Pop(&pila_a);
    Push(&auxiliar, cima);
  }

  /* Finalmente, guardo todos los elementos del lote A y del lote B. */
  int primer_b = -1;
  int primer_a = -1;
  while (!EsPilaVacia(auxiliar) || cantidad_b > 0) {
    if (cantidad_b == 0) {
      primer_a = Pop(&auxiliar);
      Encolar(&nueva_cola, primer_a);
    } else {
      if (EsPilaVacia(auxiliar)) {
        if (primer_b == -1) primer_b = Desencolar(&cola_original);
        Encolar(&nueva_cola, primer_b);
        primer_b = -1;
        cantidad_b--;
      } else {
        /*
         * Si es que ambos aun tienen elementos, entonces obtengo
         * sus primeros elementos.
         */
        
        if (primer_b == -1) primer_b = Desencolar(&cola_original);
        primer_a = Top(auxiliar);
        
        /* 
         * Analizo cual tiene que entrar primero. De acuerdo al problema,
         * la prioridad se la doy al codigo, sino al lote.
         */
        
        int codigo_a = ObtenerCodigo(primer_a);
        int codigo_b = ObtenerCodigo(primer_b);
        
        if (codigo_a <= codigo_b) {
          Encolar(&nueva_cola, primer_a);
          Pop(&auxiliar);
        } else {
          Encolar(&nueva_cola, primer_b);
          primer_b = -1;
          cantidad_b--;
        }
      }
    }
  }

  /* Imprimo la nueva cola */
  ImprimirProductos(nueva_cola);
  return 0;
}
