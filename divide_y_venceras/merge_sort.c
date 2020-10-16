#include <stdio.h>
#include <stdlib.h>

void Imprimir(int* a, int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

void Merge(int* a, int n, int* izq, int* der) {
  int len_izq = n / 2;
  int len_der = n - len_izq;
  int pos_izq, pos_der, pos;
  pos_izq = pos_der = pos = 0;
  while (pos_izq < len_izq || pos_der < pos_der) {
    if (pos_der == len_der || (pos_izq < len_izq && izq[pos_izq] < der[pos_der])) {
      a[pos++] = izq[pos_izq++];
    } else {
      a[pos++] = der[pos_der++];
    }
  }
}

void MergeSort(int* a, int n) {
  if (n < 2) return;
  int len_izq = n / 2;
  int* izq = malloc(sizeof(int) * len_izq);
  for (int i = 0; i < len_izq; i++) izq[i] = a[i];
  int len_der = n - len_izq;
  int* der = malloc(sizeof(int) * len_der);
  for (int i = 0; i < len_der; i++) der[i] = a[len_izq + i];
  MergeSort(izq, len_izq);
  MergeSort(der, len_der);
  Merge(a, n, izq, der);
  free(izq);
  free(der);
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Arreglo original: ");
  Imprimir(a, n);
  MergeSort(a, n);
  printf("Arreglo ordenado: ");
  Imprimir(a, n);
  free(a);
  return 0;
}
