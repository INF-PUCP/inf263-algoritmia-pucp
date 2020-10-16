#include <stdio.h>
#include <stdlib.h>

const int INF = 1e9;

typedef struct {
  int ind_izq;
  int ind_der;
  int suma;
} Resultado;

void Asignar(Resultado* resultado, int ind_izq, int ind_der, int suma) {
  (*resultado).ind_izq = ind_izq;
  (*resultado).ind_der = ind_der;
  (*resultado).suma = suma;
}

Resultado MaximaSumaCruzada(int* a, int l, int m, int r) {
  int izq = -INF;
  int ind_izq;
  int aux = 0;
  for (int i = m; i >= l; i--) {
    aux += a[i];
    if (aux > izq) {
      izq = aux;
      ind_izq = i;
    }
  }
  int der = -INF;
  int ind_der;
  aux = 0;
  for (int i = m + 1; i <= r; i++) {
    aux += a[i];
    if (aux > der) {
      der = aux;
      ind_der = i;
    }
  }
  Resultado resultado;
  Asignar(&resultado, ind_izq, ind_der, izq + der);
  return resultado;
}

Resultado MaximaSuma(int* a, int l, int r) {
  if (l == r) {
    Resultado resultado;
    Asignar(&resultado, l, r, a[l]);
    return resultado;
  }
  int m = (l + r) / 2;
  Resultado izq = MaximaSuma(a, l, m);
  Resultado der = MaximaSuma(a, m + 1, r);
  Resultado cruz = MaximaSumaCruzada(a, l, m, r);
  if (izq.suma >= der.suma && izq.suma >= cruz.suma) return izq;
  if (der.suma >= izq.suma && der.suma >= cruz.suma) return der;
  return cruz;
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  Resultado respuesta = MaximaSuma(a, 0, n - 1);
  printf("Maxima Suma: %d\n", respuesta.suma);
  printf("Subarreglo: a[%d, %d] =", respuesta.ind_izq, respuesta.ind_der);
  for (int i = respuesta.ind_izq; i <= respuesta.ind_der; i++) printf(" %d", a[i]);
  printf("\n");
  return 0;
}
