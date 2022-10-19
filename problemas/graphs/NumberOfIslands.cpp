// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> done;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    
    void InitializeGraph(vector<vector<char>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        done = vector<vector<bool>>(rows, vector<bool>(cols, false));
    }
    
    bool IsValid(int x, int y) {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }
    
    void DFS(int x, int y, vector<vector<char>>& grid) {
        done[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (IsValid(new_x, new_y) && grid[new_x][new_y] == '1' && !done[new_x][new_y]) {
                DFS(new_x, new_y, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        InitializeGraph(grid);
        int cnt = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1' && !done[row][col]) {
                    DFS(row, col, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
