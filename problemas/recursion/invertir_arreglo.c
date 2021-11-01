#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void Invertir(int a[], int l, int r) {
  if (l >= r) return;
  swap(&a[l], &a[r]);
  Invertir(a, l + 1, r - 1);
}

int main() {
  int n;
  int* a;
  scanf("%d", &n);
  a = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  Invertir(a, 0, n - 1);
  printf("Arreglo invertido:");
  for (int i = 0; i < n; i++) printf(" %d", a[i]);
  printf("\n");
  return 0;
}
