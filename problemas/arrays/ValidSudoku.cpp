class Solution {
 public:
  bool IsDigit(char d) {
    return '1' <= d && d <= '9';
  }

  int GetDigit(char d) {
    int digit = (int)(d - '1');
    return digit;
  }

  bool HasValidRows(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
      vector<bool> found(9, false);
      for (int col = 0; col < 9; col++) {
        if (IsDigit(board[row][col])) {
          int digit = GetDigit(board[row][col]);
          if (found[digit]) return false;
          found[digit] = true;
        }
      }
    }
    return true;
  }

  bool HasValidColumns(vector<vector<char>>& board) {
    for (int col = 0; col < 9; col++) {
      vector<bool> found(9, false);
      for (int row = 0; row < 9; row++) {
        if (IsDigit(board[row][col])) {
          int digit = GetDigit(board[row][col]);
          if (found[digit]) return false;
          found[digit] = true;
        }
      }
    }
    return true;
  }

  bool HasValidBoxes(vector<vector<char>>& board) {
    vector<vector<vector<int>>> cnt(3, vector<vector<int>>(3, vector<int>(9, 0)));
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (IsDigit(board[row][col])) {
          int digit = GetDigit(board[row][col]);
          cnt[row / 3][col / 3][digit]++;
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int d = 0; d < 9; d++) {
          if (cnt[i][j][d] > 1) {
            return false;
          }
        }
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    return HasValidRows(board) && HasValidColumns(board) && HasValidBoxes(board);
  }
};