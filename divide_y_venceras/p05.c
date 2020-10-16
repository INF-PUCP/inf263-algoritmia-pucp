#include <stdio.h>
#include <stdlib.h>

// Retorna verdadero si el elemento a[pos] es mayor o igual que el anterior
int Check(int* a, int pos) {
  if (pos == 0) return 1;
  return (a[pos] >= a[pos - 1]);
}

// El enunciado del problema me garantiza que el arreglo que recibiremos de
// primero crece y luego decrece, por lo que tiene al menos dos elementos
int Buscar(int* a, int l, int r) {
  if (Check(a, r)) return a[r];
  if (r - l <= 1) return a[l];
  int m = (l + r) / 2;
  if (Check(a, m)) return Buscar(a, m, r);
  return Buscar(a, l, m);
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Maximo elemento: %d\n", Buscar(a, 0, n - 1));
  return 0;
}
