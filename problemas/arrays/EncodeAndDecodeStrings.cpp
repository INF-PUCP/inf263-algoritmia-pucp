// https://www.lintcode.com/problem/659/description
class Solution {
 private:
  int GetDigit(char c) {
    return c - '0';
  }
  int StringToInt(string s) {
    int num = 0;
    for (char c : s) {
      num = 10 * num + GetDigit(c);
    }
    return num;
  }

 public:
  /*
   * @param strs: a list of strings
   * @return: encodes a list of strings to a single string.
   */
  string encode(vector<string> &strs) {
    // write your code here
    int n = (int)strs.size();
    string encoded = "";
    for (int i = 0; i < n; i++) {
      int len = (int)strs[i].size();
      encoded += (to_string(len) + "#" + strs[i]);
    }
    return encoded;
  }

  /*
   * @param str: A string
   * @return: dcodes a single string to a list of strings
   */
  vector<string> decode(string &str) {
    // write your code here
    vector<string> strs;
    int n = (int)str.size();
    int i = 0;
    while (i < n) {
      int j = i;
      while (str[j] != '#') j++;
      string slen = str.substr(i, j - i);
      int len = StringToInt(slen);
      strs.push_back(str.substr(j + 1, len));
      i = j + len + 1;
    }
    return strs;
  }
};