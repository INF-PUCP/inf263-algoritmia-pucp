#include <stdio.h>
#define MAX_N 20
int piezas[MAX_N][MAX_N];
int optimo[MAX_N];  /* Arreglo en el que guardo la distribucion optima */
/* Arreglo en el que guardo la distribucion temporal que sera
 * utilizada para compararla con la distribucion optima */
int temporal[MAX_N];
int usado[MAX_N];  /* i-esima maquina: 1 (usada), 0 (no usada) */

/* Funcion que suma los elementos en un arreglo */
/* O(n), pues tengo que recorrer todo el arreglo para acumular*/
int Calcular(int a[], int n) {
  int suma = 0;
  for (int i = 0; i < n; i++) suma += piezas[i][a[i]];
  return suma;
}

/* O(n), pues cada elemento de b lo asignamos al arreglo a */
int Asignar(int a[], int b[], int n) {
  for (int i = 0; i < n; i++) a[i] = b[i];
}

/* O(n^n), pues para cada trabajador, probare las n masquinas disponibles */
void Maximizar(int obrero, int total) {
  /* Si es que ya termine de analizar todos los obreros, tengo una configuracion
   * valida, sin embargo, nos falta chequear que sea la nueva optima */
  if (obrero == total) {
    int suma_temporal = Calcular(temporal, total);  /* O(n) */
    int suma_optimo = Calcular(optimo, total);  /*  O(n) */
    if (suma_temporal > suma_optimo) Asignar(optimo, temporal, total);  /* O(n) */
    return;
  } else {
    /* En caso todavia tener obreros por analizar, chequeamos sus posibilidades */
    /* O(n), pues analizo las n maquinas */
    for (int maquina = 0; maquina < total; maquina++) {
      if (!usado[maquina]) {  /* Si la maquina no habia sido utilizada */
        temporal[obrero] = maquina;  /* Le asigno al obrero actual */
        usado[maquina] = 1;  /* Marco la maquina como usada */
        Maximizar(obrero + 1, total);  /* Resuelvo el problema con los obreros restantes */
        usado[maquina] = 0;  /* Para probar otro caso, tengo que marcar la actual como no usada*/
      }
    }
  }
}

/* Funcion que incializa con un caso valido, en este caso,
 * al i-esimo trabajador le corresponde la i-esima maquina en O(n) */
void Inicializar(int n) {
  for (int i = 0; i < n; i++) optimo[i] = i;
}

// Analisis de Complejidad en tiempo del programa
// T(n) = c1 * O(1) + c2 * O(n^2) + c3 * O(n^n) + c4 * O(n)
// T(n) = O(n^n)
int main() {
  int cantidad;  /* O(1) */
  scanf("%d", &cantidad); /* O(1) */

  /* O(n ^ 2), pues hago n * n veces O(1) */
  for (int i = 0; i < cantidad; i++)
    for (int j = 0; j < cantidad; j++)
      scanf("%d", &piezas[i][j]);
  Inicializar(cantidad);  /* Coloco un caso base en O(n)*/

  /* O(n ^ n), invoco a la funcion que analiza todas las posibilidades */
  Maximizar(0, cantidad);

  /* Obtengo la suma optima e imprimo la estructura optima guardada en O(n) */
  int suma_optima = Calcular(optimo, cantidad);
  printf("Mayor cantidad de piezas diarias: %d.\n", suma_optima);
  printf("Distribucion que alcanza este optimo:\n");
  for (int i = 0; i < cantidad; i++)
    printf("Trabajador %d en Maquina %d.\n", i + 1, optimo[i] + 1);
  return 0;
}
