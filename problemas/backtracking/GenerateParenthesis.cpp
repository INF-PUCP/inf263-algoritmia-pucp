class Solution {
public:
  vector<int> current;

  void Backtracking(int position, int length, vector<string>& result) {
    if (position == length) {
      stack<int> open;
      bool is_valid = true;
      
      for (int i = 0; i < length; i++) {
        if (current[i] == 0) {
          open.push(0);
        } else {
          if (open.empty()) {
            is_valid = false;
            break;
          } else {
            open.pop();
          }
        }
      }
      if (!open.empty()) is_valid = false;

      if (is_valid) {
        string sequence = "";
        for (int i = 0; i < length; i++) {
          if (current[i] == 0) {
            sequence += '(';
          } else {
            sequence += ')';
          }
        }
        result.push_back(sequence);
      }
    } else {
      for (int i = 0; i < 2; i++) {
        current.push_back(i);
        Backtracking(position + 1, length, result);
        current.pop_back();
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    Backtracking(0, 2 * n, result);
    return result;
  }
};
