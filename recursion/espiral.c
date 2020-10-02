#include <stdio.h>
#define MAX_N 5000

int almacen[MAX_N][MAX_N];  // almacen[i][j] = codigo en la casilla (i, j)
int usado[MAX_N][MAX_N];  // usado[i][j] = la casilla (i, j) ya fue usada

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int direccion_actual = 0;
int filas, columnas;

int Check(int i, int j) {
  if (0 <= i && i < filas && 0 <= j && j < columnas && !usado[i][j]) return 1;
  return 0;
}


// O(n * m)
void Recorrer(int i, int j, int from) {
  printf("(%d, %d) : %d\n", i, j, almacen[i][j]);  // O(1)
  usado[i][j] = 1;  // O(1)
  for (int to = 0; to < 4; to++) {  // O(1)
    int actual = (from + to) % 4;
    if (Check(i + dx[actual], j + dy[actual])) {
      Recorrer(i + dx[actual], j + dy[actual], actual);
      return;
    }
  }
  return;
}

int main() {
  scanf("%d %d", &filas, &columnas);  // O(1)

  // O(n * m)
  for (int fila = 0; fila < filas; fila++) { 
    for (int columna = 0; columna < columnas; columna++) {
      scanf("%d", &almacen[fila][columna]); // O(1)
    }
  }

  // O(n * m)
  Recorrer(0, 0, 0);
  return 0;
}
