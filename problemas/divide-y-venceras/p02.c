#include <stdio.h>
#include <stdlib.h>

// Retorna verdadero si hay un 1 en la posicion actual
int Check(int* a, int pos) {
  return a[pos];
}

// Busca la ultima posicion en la cual hay un 1
// TTTFFF
int Posicion(int* a, int l, int r) {
  if (!Check(a, l)) return (l - 1);  // FFFFFF
  if (Check(a, r)) return r;  // TTTTTT
  if (r - l <= 1) return l;  // TF
  int m = (l + r) / 2;
  if (Check(a, m)) return Posicion(a, m, r);
  return Posicion(a, l, m);
}

int Solve() {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  return (n - 1 - Posicion(a, 0, n - 1));
}

int main(void) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    printf("Caso %d: %d\n", i + 1, Solve());
  }
  return 0;
}
