#include <stdio.h>
#include <stdlib.h>

int Merge(int* a, int n, int* izq, int* der) {
  int len_izq = n / 2;
  int len_der = n - len_izq;
  int pos_izq, pos_der, pos, inversiones;
  pos_izq = pos_der = pos = inversiones = 0;
  while (pos_izq < len_izq || pos_der < pos_der) {
    if (pos_der == len_der || (pos_izq < len_izq && izq[pos_izq] <= der[pos_der])) {
      a[pos++] = izq[pos_izq++];
    } else {
      inversiones += (len_izq - pos_izq);
      a[pos++] = der[pos_der++];
    }
  }
  return inversiones;
}

int MergeSort(int* a, int n) {
  if (n < 2) return 0;
  int len_izq = n / 2;
  int* izq = malloc(sizeof(int) * len_izq);
  for (int i = 0; i < len_izq; i++) izq[i] = a[i];
  int len_der = n - len_izq;
  int* der = malloc(sizeof(int) * len_der);
  for (int i = 0; i < len_der; i++) der[i] = a[len_izq + i];
  int inversiones = 0;
  inversiones += MergeSort(izq, len_izq);
  inversiones += MergeSort(der, len_der);
  inversiones += Merge(a, n, izq, der);
  free(izq);
  free(der);
  return inversiones;
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Numero de inversiones: %d\n", MergeSort(a, n));
  free(a);
  return 0;
}
