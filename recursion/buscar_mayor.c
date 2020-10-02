#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return ((a > b) ? a : b); }

int BuscarMayor(int a[], int n) {
  if (n == 1) return a[0];
  return (max(a[n - 1], BuscarMayor(a, n - 1)));
}

int main() {
  int n;
  int* a;
  scanf("%d", &n);
  a = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Mayor elemento: %d.\n", BuscarMayor(a, n));
  return 0;
}
