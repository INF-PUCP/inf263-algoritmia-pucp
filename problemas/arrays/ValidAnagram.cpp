class Solution {
public:
  vector<int> GetFrequency(const string& s) {
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    return cnt;
  }
  bool isAnagram(string s, string t) {
    return GetFrequency(s) == GetFrequency(t);
  }
};
