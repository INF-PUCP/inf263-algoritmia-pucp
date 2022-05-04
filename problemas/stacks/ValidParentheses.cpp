// https://leetcode.com/problems/valid-parentheses/
class Solution {
 private:
  unordered_set<char> openings;
  unordered_map<char, char> closings;
  bool IsOpening(char c) {
    return openings.count(c) > 0;
  }
  bool Match(char opening, char closing) {
    return closings[opening] == closing;
  }

 public:
  Solution(void) {
    openings.insert('(');
    openings.insert('[');
    openings.insert('{');
    closings['('] = ')';
    closings['['] = ']';
    closings['{'] = '}';
  }
  bool isValid(string s) {
    stack<char> in_progress;
    for (char c : s) {
      if (IsOpening(c)) {
        in_progress.push(c);
      } else {
        if (in_progress.empty() || !Match(in_progress.top(), c)) {
          return false;
        }
        in_progress.pop();
      }
    }
    return in_progress.empty();
  }
};