// https://leetcode.com/problems/valid-palindrome/submissions/

class Solution {
 public:
  bool IsDigit(char c) {
    return ('0' <= c && c <= '9');
  }

  bool IsLower(char c) {
    return ('a' <= c && c <= 'z');
  }

  bool IsUpper(char c) {
    return ('A' <= c && c <= 'Z');
  }

  bool IsAlphanumeric(char c) {
    return IsDigit(c) || IsLower(c) || IsUpper(c);
  }

  char FormatChar(char c) {
    if (IsDigit(c)) return c;
    if (IsLower(c)) return c;
    return tolower(c);
  }

  string GetAlphanumeric(string s) {
    string alphanumeric = "";
    for (char c : s) {
      if (IsAlphanumeric(c)) {
        alphanumeric += FormatChar(c);
      }
    }
    return alphanumeric;
  }

  bool IsPalindrome(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - 1 - i]) {
        return false;
      }
    }
    return true;
  }

  bool isPalindrome(string s) {
    string alphanumeric = GetAlphanumeric(s);
    return IsPalindrome(alphanumeric);
  }
};