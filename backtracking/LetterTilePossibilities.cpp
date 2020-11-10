class Solution {
private:
  vector<int> factorial;
  vector<int> current;

public:
  int Backtracking(int pos, int len, const vector<int>& cnt) {
    if (pos == cnt.size()) {
      bool is_valid = false;
      int size = 0; 
      for (int times : current) {
        if (times != 0) {
          is_valid = true;
          size += times;
        }
      }
      if (!is_valid) return 0;
      int result = factorial[size];
      for (int times : current) result /= factorial[times];
      return result;
    }
    int result = 0;
    current.push_back(-1);
    for (int val = 0; val <= cnt[pos]; val++) {
      current[pos]++;
      result += Backtracking(pos + 1, len, cnt);
    }
    current.pop_back();
    return result;
  }

  int numTilePossibilities(string tiles) {
    int n = tiles.size();
    factorial.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
      factorial[i] = factorial[i - 1] * i;

    map<char, int> count;
    for (char chr : tiles) count[chr]++;
    vector<int> cnt;
    for (auto it = count.begin(); it != count.end(); it++)
      cnt.push_back(it->second);

    return Backtracking(0, n, cnt);
  }
};
