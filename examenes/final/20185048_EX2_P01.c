#include <stdio.h>
#define MAX_N 10
int cantidad[MAX_N];
int capacidad[MAX_N];
int temporal[MAX_N];
int n, m;

/*
 * Metodo: EsValido
 * Uso: if (EsValido()) . . .
 * --------------------------
 * Retorna 1 si en cada posicion no se excede la capacidad, 0 en otro caso.
 */
int EsValido(void) {
  for (int i = 0; i < m; i++) if (temporal[i] > capacidad[i]) return 0;
  return 1;
}

/*
 * Metodo: Imprimir
 * Uso: Imprimir();
 * ----------------
 * Imprime la solucion con el formato especificado en el problema.
 */
void Imprimir(void) {
  printf("{");
  for (int i = 0; i < m; i++) {
    if (i > 0) printf(", ");
    printf("%d", temporal[i]);
  }
  printf("}\n");
}

/*
 * Metodo: Backtracking
 * Uso: Backtracking(pos);
 * -----------------------------
 * Metodo que realiza un backtracking de los productos [pos .. n - 1].
 * Este metodo asignara a cada producto un rack.
 */
void Backtracking(int pos) {
  if (pos == n) {
    if (EsValido()) Imprimir();
  } else {
    /* Para cada posible lugar en el cual el producto actual puede ser
     * colocado, analizaremos el problema */
    for (int lugar = 0; lugar < m; lugar++) {
      temporal[lugar] += cantidad[pos];
      Backtracking(pos + 1);
      temporal[lugar] -= cantidad[pos];
    }
  }
}

/*
 * Metodo: Backtracking2
 * Uso: Backtracking2(pos);
 * -----------------------------
 * Metodo que realiza un backtracking de los productos [pos .. n - 1].
 * Este metodo asignara a cada producto un rack.
 * Para que no hayan repeticiones de conteo, el segundo parametro prev
 * determinar que podemos asignarle los rack [prev .. m - 1].
 */
int posicion[MAX_N];

void Backtracking2(int pos) {
  if (pos == n) {
    if (EsValido()) {
      for (int rack = 0; rack < m; rack++) {
        printf("Productos en rack %d: ", rack);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          if (posicion[i] == rack) {
            if (cnt > 0) printf(", ");
            printf("producto %d con cantidad %d", i, cantidad[i]);
            cnt++;
          }
        }
        if (cnt == 0) printf("No hay productos.");
        printf("\n");
      }
      printf("\n");
    }
  } else {
    /* Para cada posible lugar en el cual el producto actual puede ser
     * colocado, analizaremos el problema */
    for (int lugar = 0; lugar < m; lugar++) {
      temporal[lugar] += cantidad[pos];
      posicion[pos] = lugar;
      Backtracking2(pos + 1);
      temporal[lugar] -= cantidad[pos];
    }
  }
}



int main(void) {
  /* Lectura de datos */
  printf("Ingrese la cantidad de productos: ");
  scanf("%d", &n);
  printf("Ingrese la cantidad de racks: ");
  scanf("%d", &m);

  for (int i = 0; i < n; i++) {
    printf("Ingrese la cantidad del producto %d: ", i);
    scanf("%d", &cantidad[i]);
  }

  for (int i = 0; i < m; i++) {
    printf("Ingrese la capacidad del rack %d: ", i);
    scanf("%d", &capacidad[i]);
  }

  /* Pregunta 1.b. */
  printf("Resultados al ubicar los productos:\n");
  Backtracking(0);
  printf("\n");

  /* Pregunta 1.c. */
  printf("Posibles combinaciones de productos:\n");
  Backtracking2(0);
  return 0;
}
