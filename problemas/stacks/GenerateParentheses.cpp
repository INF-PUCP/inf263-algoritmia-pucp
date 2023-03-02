// https://leetcode.com/problems/generate-parentheses/
class Solution {
 private:
  stack<char> expression;
  vector<string> expressions;

  void GenerateExpression(void) {
    string str = "";
    while (!expression.empty()) {
      str += expression.top();
      expression.pop();
    }
    reverse(str.begin(), str.end());
    expressions.push_back(str);
    for (char chr : str) {
      expression.push(chr);
    }
  }
  
  void Backtrack(int previous_remaining_openings, int previous_unpaired_closings) {
    expression.push('(');

    int remaining_openings = previous_remaining_openings - 1;
    int unpaired_closings = previous_unpaired_closings + 1;

    if (remaining_openings == 0) {
      for (int i = 0; i < unpaired_closings; i++) {
        expression.push(')');
      }
      GenerateExpression();
    } else {
      for (int i = 0; i <= unpaired_closings; i++) {
        if (i > 0) expression.push(')');
        Backtrack(remaining_openings, unpaired_closings - i);
      }
    }

    for (int i = 0; i < unpaired_closings; i++) {
      expression.pop();
    }
    expression.pop();
  }
 public:
  vector<string> generateParenthesis(int n) {
    Backtrack(n, 0);
    return expressions;
  }
};