// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
 private:
  unordered_set<string> operands;
  stack<int> st;
  bool IsOperand(string s) {
    return operands.count(s) > 0;
  }
 public:
  Solution(void) {
    operands.insert("+");
    operands.insert("-");
    operands.insert("*");
    operands.insert("/");
  }
  int evalRPN(vector<string>& tokens) {
    for (string token : tokens) {
      if (IsOperand(token)) {
        int second = st.top();
        st.pop();
        int first = st.top();
        st.pop();
        int tmp = 0;
        if (token == "+") {
          tmp = first + second;
        }
        if (token == "-") {
          tmp = first - second;
        }
        if (token == "*") {
          tmp = first * second;
        }
        if (token == "/") {
          tmp = first / second;
        }
        st.push(tmp);
      } else {
        st.push(stoi(token));
      }
    }
    return st.top();
  }
};