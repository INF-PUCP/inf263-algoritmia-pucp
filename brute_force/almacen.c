#include <stdio.h>
#include <stdlib.h>

void EnteroABinario(int estado[], int n, int mask) {
  for (int bit = 0; bit < n; bit++) {
    estado[n - 1 - bit] = mask & 1;
    mask >>= 1;
  }
}


int CalcularSuma(int** actual, int** almacen, int n, int m) {
  int suma = 0;
  if (actual[0][0] == 1) return -1;
  int x, y;
  int dx[4] = {-1, -1, -1, 0};
  int dy[4] = {-1, 0, 1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (actual[i][j]) {
        for (int k = 0; k < 4; k++) {
          x = i + dx[k];
          y = j + dy[k];
          if (0 <= x && x < n
              && 0 <= y && y < m
              && actual[x][y]) {
            return -1;
          }
        }
        // No hubo cajas que me arruinaron
        suma += almacen[i][j];
      }
    }
  }
  return suma;
}

void ImprimirTabla(int** tabla, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", tabla[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  int n, m;
  printf("Ingrese la cantidad de filas: ");
  scanf("%d", &n);
  printf("Ingrese la cantidad de columnas: ");
  scanf("%d", &m);
  int** almacen;  // valor de cada caja
  int** actual;  // almacen actual dado un estado
  almacen = (int**) malloc(sizeof(int*) * n);
  actual = (int**) malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    almacen[i] = (int*) malloc(sizeof(int) * m);
    actual[i] = (int*) malloc(sizeof(int) * m);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      //scanf("%d", &almacen[i][j]);
      almacen[i][j] = rand() % 100;

  int elementos = n * m;
  int combinaciones = 1 << (elementos);
  int estado[elementos];  // estado[i] : caja en i esima posicion
  int solucion[elementos];
  int mejorSuma, mejorSolucion;
  mejorSuma = mejorSolucion = 0;
  for (int i = 0; i < elementos; i++) solucion[i] = 0;

  for (int mask = 0; mask < combinaciones; mask++) {
    EnteroABinario(estado, elementos, mask);
    // En la matriz actual coloco las cajas que estoy utilizando
    for (int bit = 0; bit < elementos; bit++) {
      int row = bit / m;
      int col = bit % m;
      actual[row][col] = estado[bit];
    }
    // Chequeo si la matriz actual es valida
    int sumaActual = CalcularSuma(actual, almacen, n, m);
    if (sumaActual != -1) {
      if (sumaActual >= mejorSuma) {
        mejorSuma = sumaActual;
        mejorSolucion = mask;
      }
    }
  }

  EnteroABinario(estado, elementos, mejorSolucion);
  printf("Mejor suma: %d\n", mejorSuma);
  for (int bit = 0; bit < elementos; bit++) {
    int row = bit / m;
    int col = bit % m;
    actual[row][col] = estado[bit];
  }
  printf("\nAlmacen original:\n");
  ImprimirTabla(almacen, n, m);
  printf("\nSolucion:\n");
  ImprimirTabla(actual, n, m);

  // Libero memoria
  for (int i = 0; i < n; i++) {
    free(almacen[i]);
    free(actual[i]);
  }
  free(almacen);
  free(actual);
  return 0;
}
