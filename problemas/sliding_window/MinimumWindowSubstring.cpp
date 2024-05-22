// https://leetcode.com/problems/minimum-window-substring/
struct Map {
  unordered_map<char, int> m;
  Map(void) {
    for (int i = 0; i < 26; i++) {
      m[(char)('a' + i)] = 0;
      m[(char)('A' + i)] = 0;
    }
  }
  void Add(char c) {
    m[c]++;
  }
  void Remove(char c) {
    m[c]--;
  }
  int Get(char c) {
    return m[c];
  }
};

bool Contains(Map& big, Map& small) {
  vector<char> base = {'a', 'A'};
  for (char b : base) {
    for (int i = 0; i < 26; i++) {
      if (big.Get((char)(b + i)) < small.Get((char)(b + i))) {
        return false;
      }
    }
  }
  return true;
}

class Solution {
 public:
  string minWindow(string s, string t) {
    Map target, window;
    for (char c : t) target.Add(c);
    
    int min_window = INT_MAX;
    int init = -1;

    int n = (int)s.size();
    int l = 0;
    for (int r = 0; r < n; r++) {
      window.Add(s[r]);
      while (l <= r) {
        window.Remove(s[l]);
        if (!Contains(window, target)) {
          window.Add(s[l]);
          break;
        }
        l++;
      }
      if (Contains(window, target)) {
        int len = r - l + 1;
        if (len < min_window) {
          min_window = len;
          init = l;
        }
      }
    }

    if (min_window == INT_MAX) return "";
    return s.substr(init, min_window);
  }
};