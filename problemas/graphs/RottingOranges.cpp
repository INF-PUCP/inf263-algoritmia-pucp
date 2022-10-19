// https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> d;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    void InitializeGraph(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        d = vector<vector<int>>(rows, vector<int>(cols, -1));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    d[row][col] = 0;
                }
            }
        }
    }
    
    bool IsValid(int row, int col) {
        return 0 <= row && row < rows && 0 <= col && col < cols;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        InitializeGraph(grid);
        
        // BFS
        queue<pair<int, int>> tour;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (d[row][col] == 0) {
                    tour.push({row, col});
                }
            }
        }

        while (!tour.empty()) {
            pair<int, int> front = tour.front();
            tour.pop();
            int row = front.first;
            int col = front.second;
            for (int i = 0; i < 4; i++) {
                int new_row = row + dx[i];
                int new_col = col + dy[i];
                if (IsValid(new_row, new_col) && grid[new_row][new_col] > 0) {
                    if (d[new_row][new_col] == -1 || d[row][col] + 1 < d[new_row][new_col]) {
                        d[new_row][new_col] = d[row][col] + 1;
                        tour.push({new_row, new_col});
                    }
                }
            }
        }
        
        // Minimum number of minutes that must elapse until no cell has a fresh orange.
        int mx = -1;
        int good_oranges = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) good_oranges++;
                mx = max(mx, d[i][j]);
                if (grid[i][j] == 1 && d[i][j] == -1) {
                    return -1;
                }
            }
        }
        if (good_oranges == 0) return 0;
        return mx;
    }
};
