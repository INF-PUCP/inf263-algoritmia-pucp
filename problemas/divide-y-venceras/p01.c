#include <stdio.h>
#include <stdlib.h>

int Check(int* a, int n, int pos) {
  int cur = 2 * pos;
  int next = 2 * pos + 1;
  if (next == n) return 0;
  if (a[cur] != a[next]) return 0;
  return 1;
}

int Buscar(int* a, int n, int l, int r) {
  if (!Check(a, n, l)) return 2 * l;
  if (r - l <= 1) return 2 * r;
  int m = (l + r) / 2;
  if (Check(a, n, m)) return Buscar(a, n, m, r);
  return Buscar(a, n, l, m);
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Elemento solitario: %d\n", Buscar(a, n, 0, n / 2));
  return 0;
}
