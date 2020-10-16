#include <stdio.h>
#include <stdlib.h>

const int INF = 1e9;
int* acc;

int max(int a, int b) {
  return ((a > b) ? a : b);
}

int MaxSum(int* a, int l, int r) {
  if (l > r) return -INF;
  int sum1 = acc[r] - ((l > 0) ? acc[l - 1] : 0);
  int sum2 = MaxSum(a, l + 1, r);
  int sum3 = MaxSum(a, l, r - 1);
  return max(sum1, max(sum2, sum3));
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* a = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  acc = malloc(sizeof(int) * n);
  acc[0] = a[0];
  for (int i = 1; i < n; i++) acc[i] = acc[i - 1] + a[i];
  printf("Maxima suma: %d\n", MaxSum(a, 0, n - 1));
  return 0;
}
