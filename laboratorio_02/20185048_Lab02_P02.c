#include <stdio.h>
#define MAX_N 100
int mapa[MAX_N][MAX_N];
int usado[MAX_N][MAX_N];
int filas, columnas;
/*
 * Leyenda del movimiento
 * 0: derecha
 * 1: abajo
 * 2: izquierda
 * 3: arriba
 *
 * dx[i] = desplazarme  enla i-esima direccion de filas
 * dy[i] = desplazarme en la i-esima direccion de columnas
 */
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

/* Estructura que me ayudara a representar las coordenadas del robot */
typedef struct _Punto {
  int x;
  int y;
} Punto;

/* Funcion que verifica si un punto sigue perteneciendo al tablero
 * Como siempre realizar una cantidad constante de operaciones es O(1) */
int Valido(Punto posicion) {
  if (0 <= posicion.x && posicion.x < filas &&
      0 <= posicion.y && posicion.y < columnas) return 1;
  return 0;
}

/* Funcion recursiva que cuenta cuantas unidades estan en el rastreo del robot
 * Analisis de Complejidad en tiempo
 * T(n, m) = c1 O(1) + c2 O(n) + c3 O(m) + T(n + 1, m)
 * T(n, m) = O(n + m) * T(n + 1, m)
 * En el peor de los casos, realizaremos la recursion max(n, m) veces
 * Luego, T(n, m) = O(n * m)
 */
int Rastrear(Punto posicion, int direccion) {
  int unidades = 0;  /* Cantidad de nuevas unidades encontradas en este recorrido */
  /* Primero me fijo si estoy parado sobre un elemento no utilizado */
  if (mapa[posicion.x][posicion.y] && !usado[posicion.x][posicion.y]) {
    unidades++;
    usado[posicion.x][posicion.y] = 1;
  }
  /* Luego, recorro horizontalmente y verticalmente */
  /* Recorrido vertical */
  for (int i = 0; i < filas; i++) {
    if (mapa[i][posicion.y] && !usado[i][posicion.y]) {
      unidades++;
      usado[i][posicion.y] = 1;
    }
  }
  /* Recorrido horizontal */
  for (int i = 0; i < columnas; i++) {
    if (mapa[posicion.x][i] && !usado[posicion.x][i]) {
      unidades++;
      usado[posicion.x][i] = 1;
    }
  }
  /* Finalmente, si puede seguir moviendome, recursivamente rastreo lo restante */
  Punto nuevo;
  nuevo.x = posicion.x + dx[direccion];
  nuevo.y = posicion.y + dy[direccion];
  if (Valido(nuevo)) return unidades + Rastrear(nuevo, direccion);
  return unidades;
}

int main() {
  int direccion;
  scanf("%d %d %d", &filas, &columnas, &direccion);
  /* Leemos los datos en O(n * m)*/
  for (int i = 0; i < filas; i++)
    for (int j = 0; j < columnas; j++)
      scanf("%d", &mapa[i][j]);
  /* Coordenadas iniciales */
  Punto inicio;
  scanf("%d %d", &inicio.x, &inicio.y);
  int cantidad = Rastrear(inicio, direccion);
  /* Finalmente, imprimo cuantos encontre en mi recorrido */
  printf("Cantidad de unidades encontradas durante el rastreo: %d.\n", cantidad);
  return 0;
}
