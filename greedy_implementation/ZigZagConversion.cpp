class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int elementsPerBlock = 2 * numRows - 2;
    int length = s.size();
    int blocks = (length + elementsPerBlock - 1) / elementsPerBlock;

    string answer = "";
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < blocks; j++) {
        int current = i + j * elementsPerBlock;
        if (current < length) answer += s[current];
        if (0 < i && i < numRows - 1) {
          int distance = numRows - 1 - i;
          current = current + 2 * distance;
          if (current < length) answer += s[current];
        }
      }
    }
    return answer;
  }
};
