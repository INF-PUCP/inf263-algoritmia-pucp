#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Persona_ {
  int sano;
  int x;
  int y;
} Persona;

// Distancia al cuadrado usando enteros para no perder precision
int dist2(Persona p1, Persona p2) {
  int dx = abs(p1.x - p2.x);
  int dy = abs(p1.y - p2.y);
  return (dx * dx + dy * dy);
}

double dist(Persona p1, Persona p2) {
  return sqrt((double)(dist2(p1, p2)));
}

int main() {
  int n, R;
  scanf("%d %d", &n, &R);
  Persona personas[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &personas[i].sano, &personas[i].x, &personas[i].y);
    personas[i].sano = !personas[i].sano;
  }
  int m;
  scanf("%d", &m);
  Persona movimiento[m];
  for (int i = 0; i < m; i++) {
    movimiento[i].sano = i + 1;
    scanf("%d %d", &movimiento[i].x, &movimiento[i].y);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!personas[j].sano && dist2(movimiento[i], personas[j]) <= R * R) {
        double distancia = dist(movimiento[i], personas[j]);
        printf("Persona podria haberse contagiado en su movimiento %d por la persona %d con nivel de cercania %f\n", i + 1, j + 1, distancia);
      }
    }
  }
  return 0;
}
