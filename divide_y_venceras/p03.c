#include <stdio.h>
#include <stdlib.h>

// Retorna verdadero si el elemento actual es menor o igual al extremo derecho
int Check(int* a, int n, int pos) {
  return (a[pos] <= a[n - 1]);
}

// Encuentra la posicion del primer elemento menor o igual al extremo derecho
int Buscar(int* a, int n, int l, int r) {
  if (Check(a, n, l)) return a[l];  // TTTT
  if (r - l <= 1) return a[r]; // FT
  int m = (l + r) / 2;
  if (Check(a, n, m)) return Buscar(a, n, l, m);
  return Buscar(a, n, m, r);
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Menor elemento: %d\n", Buscar(a, n, 0, n - 1));
  free(a);
  return 0;
}
