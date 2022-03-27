#include <stdio.h>

void Casita(int n, int cnt, int m) {
  if (cnt == 2 * m) return;
  for (int i = 0; i < n; i++) printf("*");
  int p = ((cnt <= m) ? cnt : (2 * m - cnt));
  for (int i = 0; i < p; i++) printf("*");
  printf("\n");
  Casita(n, cnt + 1, m);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Casita(n, 1, m);
  return 0;
}
