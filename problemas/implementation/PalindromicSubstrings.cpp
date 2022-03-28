class Solution {
public:
  int CountPalindromes(int center, const string& s) {
    int len = s.size();
    int count = 1;
    
    int size = 1;
    while (center - size >= 0 && center + size < len) {
      if (s[center - size] == s[center + size]) {
        count++;
        size++;
      } else {
        break;
      }
    }

    size = 1;
    while (center - size + 1 >= 0 && center + size < len) {
      if (s[center - size + 1] == s[center + size]) {
        count++;
        size++;
      } else {
        break;
      }
    }
    return count;
  }

  int countSubstrings(string s) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      count += CountPalindromes(i, s);
    }
    return count;
  }
};
