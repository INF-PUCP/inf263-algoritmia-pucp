class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> max_col(cols, 0);
    vector<int> max_row(rows, 0);
    
    for (int col = 0; col < cols; col++) {
      for (int row = 0; row < rows; row++) {
        max_col[col] = max(max_col[col], grid[row][col]);
        max_row[row] = max(max_row[row], grid[row][col]);
      }
    }

    int result = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result += (min(max_row[i], max_col[j]) - grid[i][j]);
      }
    }
    return result;
  }
};
