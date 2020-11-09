class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int rows, cols;
    rows = cols = n / 2;
    if (n % 2 != 0) rows++;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int aux = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = aux;
      }
    }
  }
};
