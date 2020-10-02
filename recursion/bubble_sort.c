#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void BubbleSort(int a[], int l, int r) {
  if (l == r) return;
  int minimo = l;
  for (int i = l + 1; i <= r; i++) if (a[i] < a[minimo]) minimo = i;
  swap(&a[l], &a[minimo]);
  BubbleSort(a, l + 1, r);
}

int main() {
  int n;
  scanf("%d", &n);
  int* a;
  a = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  BubbleSort(a, 0, n - 1);
  printf("Arreglo ordenado:");
  for (int i = 0; i < n; i++) printf(" %d", a[i]);
  printf("\n");
  return 0;
}
