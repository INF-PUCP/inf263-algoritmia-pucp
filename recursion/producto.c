#include <stdio.h>

int Producto(int a, int b) {
  if (a == 0) return 0;
  return b + Producto(a - 1, b);
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d x %d = %d.\n", a, b, Producto(a, b));
  return 0;
}
