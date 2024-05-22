// https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
 private:
  int GetIndex(char c) {
    return c - 'A';
  }

  bool IsValid(int replacements, const vector<int>& frequencies) {
    int mx = 0;
    int cnt = 0;
    for (int frequency : frequencies) {
      mx = max(mx, frequency);
      cnt += frequency;
    }
    return mx + replacements >= cnt;
  }

 public:
  int characterReplacement(string s, int k) {
    int n = (int)s.size();
    int left = 0;
    int mx = 0;
    vector<int> frequencies(26, 0);
    for (int right = 0; right < n; right++) {
      int back = GetIndex(s[right]);
      frequencies[back]++;
      while (!IsValid(k, frequencies)) {
        int front = GetIndex(s[left]);
        frequencies[front]--;
        left++;
      }
      mx = max(mx, right - left + 1);
    }
    return mx;
  }
};