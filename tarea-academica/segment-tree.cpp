#include <iostream>
#include <vector>
using namespace std;

typedef long long Long;

struct SegmentTree {
  vector<Long> tree;

  SegmentTree(int n) {
    tree.resize(4 * n, 0);
  }

  // O(n)
  void Build(vector<Long>& a, int id, int tl, int tr) {
    if (tl == tr) {
      tree[id] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      Build(a, 2 * id, tl, tm);
      Build(a, 2 * id + 1, tm + 1, tr);
      tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
  }

  // O(lg(n))
  void Update(int pos, Long val, int id, int tl, int tr) {
    if (tl == tr) {
      tree[id] = val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        Update(pos, val, 2 * id, tl, tm);
      } else {
        Update(pos, val, 2 * id + 1, tm + 1, tr);
      }
      tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
  }

  // O(lg(n))
  Long Query(int l, int r, int id, int tl, int tr) {
    if (l <= tl && tr <= r) return tree[id];
    int tm = (tl + tr) / 2;
    if (r <= tm) return Query(l, r, 2 * id, tl, tm);
    if (tm < l) return Query(l ,r, 2 * id + 1, tm + 1, tr);
    return Query(l, r, 2 * id, tl, tm) + Query(l, r, 2 * id + 1, tm + 1, tr);
  }
};

// Total time complexity: O(n^2)
// Total space complexity: O(n)
int main(void) {
  // Tenemos n resistores
  // r_1, r_2, ..., r_n
  // Tenemos q consultas
  // Cada consulta puede ser de dos tipos:
  // 1 pos val: Cambiar el valor de la resistencia en la posicion 'pos' a 'val'
  // 2 L R: Hallar la resistencia equivalente entre r_L ... r_R
  // Restricciones:
  // r_i <= 10^9, 1 <= i <= n
  // n <= 10^5
  // q <= 10^5
  int n;
  cin >> n;
  vector<Long> res(n); // O(n)
  for (int i = 0; i < n; i++) cin >> res[i]; // O(n)
  
  int q;
  cin >> q;

  // O(qn)
  /*
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int pos, val;
      cin >> pos >> val;
      res[pos] = val;
    } else {
      int l, r;
      cin >> l >> r;
      int req = 0;
      for (int i = l; i <= r; i++) req += res[i]; // O(n)
      cout << req << '\n';
    }
  }
  */
  SegmentTree st(n);
  st.Build(res, 1, 0, n - 1);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int pos, val;
      cin >> pos >> val;
      st.Update(pos, val, 1, 0, n - 1);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.Query(l, r, 1, 0, n - 1) << '\n';
    }
  }
  return 0;
}
