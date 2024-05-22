// https://leetcode.com/problems/longest-substring-without-repeating-characters/https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
 private:
  bool HasRepeatingCharacters(const unordered_map<char, int>& frequencies) {
    for (auto p : frequencies) {
      if (p.second > 1) return true;
    }
    return false;
  }

 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> frequencies;
    int n = (int)s.size();
    int l = 0;
    int mx = 0;
    for (int r = 0; r < n; r++) {
      if (frequencies.count(s[r]) == 0) {
        frequencies[s[r]] = 0;
      }
      frequencies[s[r]]++;
      while (HasRepeatingCharacters(frequencies)) {
        frequencies[s[l]]--;
        if (frequencies[s[l]] == 0) {
          frequencies.erase(s[l]);
        }
        l++;
      }
      mx = max(mx, r - l + 1);
    }
    return mx;
  }
};