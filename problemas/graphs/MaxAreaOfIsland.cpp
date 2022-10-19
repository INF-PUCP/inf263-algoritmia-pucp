// https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> done;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    
    void InitializeGraph(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        done = vector<vector<bool>>(rows, vector<bool>(cols, false));
    }
    
    bool IsValid(int row, int col) {
        return 0 <= row && row < rows && 0 <= col && col < cols;
    }
    
    int DFS(int row, int col, vector<vector<int>>& grid) {
        done[row][col] = true;
        int sz = 1;
        for (int i = 0; i < 4; i++) {
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            if (IsValid(new_row, new_col) && grid[new_row][new_col] == 1 && !done[new_row][new_col]) {
                sz += DFS(new_row, new_col, grid);
            }
        }
        return sz;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        InitializeGraph(grid);
        int mx = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (IsValid(row, col) && grid[row][col] == 1 && !done[row][col]) {
                    mx = max(mx, DFS(row, col, grid));
                }
            }
        }
        return mx;
    }
};
