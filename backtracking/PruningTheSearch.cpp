#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

const int N = 7;

bool is_used[N][N];
int cnt = 0;
int ans = 0;

// up, left, down, right
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool IsValid(const int& x, const int& y) {
  return (0 <= x && x < N && 0 <= y && y < N);
}

void Count(int i, int j) {
  if (!IsValid(i, j)) return;
  if (is_used[i][j]) return;
  if (i == N - 1 && j == N - 1) {
    if (cnt == 48) ans++;
    return;
  }

  int x, y, k, len = 0;
  int next_move[4];
  for (k = 0; k < 4; k++) {
    x = i + dx[k];
    y = j + dy[k];
    if (IsValid(x, y) && !is_used[x][y]) {
      next_move[len] = k;
      len++;
    }
  }
  if (len == 0) return;
  if (len == 2 && abs(next_move[1] - next_move[0]) == 2) return;

  is_used[i][j] = true;
  cnt++;
  for (k = 0; k < len; k++) {
    x = i + dx[next_move[k]];
    y = j + dy[next_move[k]];
    Count(x, y);
  }
  is_used[i][j] = false;
  cnt--;
}

int main(void) {
  FAST_IO;
  is_used[0][0] = true;
  cnt = 1;
  Count(0, 1);
  ans *= 2;
  cout << ans << '\n';
  return 0;
}
