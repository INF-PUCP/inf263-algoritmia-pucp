#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int GetIndex(char c) {
    return c - 'a';
  }
  vector<int> GetFrequencies(const string& s) {
    vector<int> frequencies(26, 0);
    for (char c : s) frequencies[GetIndex(c)]++;
    return frequencies;
  }
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    vector<int> target = GetFrequencies(s1);

    vector<int> current(26, 0);
    for (int i = 0; i < (int)s1.size() - 1; i++) {
      current[GetIndex(s2[i])]++;
    }

    for (int right = (int)s1.size() - 1; right < (int)s2.size(); right++) {
      current[GetIndex(s2[right])]++;
      if (current == target) return true;
      int left = right - (int)s1.size() + 1;
      current[GetIndex(s2[left])]--;
    }
    return false;
  }
};