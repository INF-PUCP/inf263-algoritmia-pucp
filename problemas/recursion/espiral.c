#include <stdio.h>
int almacen[100][100], usado[100][100], dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1}, n, m;
int Check(int i, int j) { return ((0 <= i && i < n && 0 <= j && j < m && !usado[i][j]) ? 1 : 0); }
void Recorrer(int i, int j, int from) {
  printf("(%d, %d) : %d\n", i, j, almacen[i][j]); usado[i][j] = 1;
  for (int to = 0; to < 4; to++) { 
    int cur = (from + to) % 4;
    if (Check(i + dx[cur], j + dy[cur])) { Recorrer(i + dx[cur], j + dy[cur], cur); return; }
  }
}
int main() {
  scanf("%d %d", &n, &m); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &almacen[i][j]);
  Recorrer(0, 0, 0); return 0;
}
