class DisjointSets {
public:
  vector<int> parent;
  vector<int> size;
  void MakeSet(int u) {
    parent[u] = u;
    size[u] = 1;
  }
  DisjointSets(int n) {
    parent = vector<int>(n);
    size = vector<int>(n);
    for (int i = 0; i < n; i++) {
      MakeSet(i);
    }
  }
  int Find(int u) {
    if (parent[u] == u) return u;
    return (parent[u] = Find(parent[u]));
  }
  void Join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
      if (size[u] > size[v]) swap(u, v);
      parent[u] = v;
      size[v] += size[u];
    }
  }
};
class Solution {
public:
  void Compress(int col, vector<vector<int>>& stones) {
    int n = (int) stones.size();
    vector<pair<int, int>> pairs;
    for (int row = 0; row < n; row++) pairs.push_back({stones[row][col], row});
    sort(pairs.begin(), pairs.end());
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0 && pairs[i].first != pairs[i - 1].first) cur++;
      stones[pairs[i].second][col] = cur;
    }
  }
  int removeStones(vector<vector<int>>& stones) { 
    int n = (int) stones.size();
    for (int col = 0; col < 2; col++) Compress(col, stones);
    vector<vector<vector<int>>> done(n, vector<vector<int>>(2));
    DisjointSets dsu(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        if (done[stones[i][j]][j].size() > 0) {
          dsu.Join(done[stones[i][j]][j].end()[-1], i);
        }
      }
      for (int j = 0; j < 2; j++) {
        done[stones[i][j]][j].push_back(i);
      }
    }
    set<int> components;
    for (int i = 0; i < n; i++) components.insert(dsu.Find(i));
    int max_removed_stones = n - (int) components.size();
    return max_removed_stones;
  }
};