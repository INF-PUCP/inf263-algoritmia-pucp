#include <stdio.h>
#include <stdlib.h>

struct Producto {
  int codigo;
  int serie;
  int tipo;
};

// Posicion del primer elemento >= x
int inf(struct Producto* p, int n, int x) {
  int l = 0;
  int r = n - 1;
  if (p[r].tipo < x) return -1;
  if (p[l].tipo >= x) return l;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (p[m].tipo >= x) r = m;
    else l = m;
  }
  if (p[l].tipo >= x) return l;
  return r;
}

// Posicion del ultimo elemento <= x
int sup(struct Producto* p, int n, int x) {
  int l = 0;
  int r = n - 1;
  if (p[l].tipo > x) return -1;
  if (p[r].tipo <= x) return r;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (p[m].tipo <= x) l = m;
    else r = m;
  }
  if (p[r].tipo <= x) return r;
  return l;
}

int main() {
  int n;
  scanf("%d", &n);
  struct Producto* productos;
  productos = (struct Producto*) malloc(sizeof(struct Producto) * n);
  for (int i = 0; i < n; i++) scanf("%d %d %d", &productos[i].codigo, &productos[i].serie, &productos[i].tipo);
  for (int tipo = 1; tipo <= 10; tipo++) {
    int primero = inf(productos, n, tipo);
    int ultimo = sup(productos, n, tipo);
    int total = ultimo - primero + 1;
    if (total > 0) printf("Hay %d productos del tipo %d.\n", total, tipo);
  }
  return 0;
}
