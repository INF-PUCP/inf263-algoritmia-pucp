// https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> solutions;
    vector<string> solution;
    vector<bool> used_cols;
    vector<bool> used_r_d_diags;
    vector<bool> used_r_u_diags;
    
    
    void Backtrack(int i, int n) {
        if (i == n) {
            solutions.push_back(solution);
            return;
        }
        for (int j = 0; j < n; j++) {
            int r_d_diag = i + j;
            int r_u_diag = i - j + n - 1;
            
            if (used_cols[j] || used_r_d_diags[r_d_diag] || used_r_u_diags[r_u_diag]) continue;
            
            solution[i][j] = 'Q';
            used_cols[j] = true;
            used_r_d_diags[r_d_diag] = true;
            used_r_u_diags[r_u_diag] = true;
            
            Backtrack(i + 1, n);
            
            solution[i][j] = '.';
            used_cols[j] = false;
            used_r_d_diags[r_d_diag] = false;
            used_r_u_diags[r_u_diag] = false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        used_cols = vector<bool>(n, false);
        used_r_d_diags = vector<bool>(2 * n - 1, false);
        used_r_u_diags = vector<bool>(2 * n - 1, false);
        string row = "";
        for (int i = 0; i < n; i++) {
            row += '.';
        }
        for (int i = 0; i < n; i++) {
            solution.push_back(row);
        }
        Backtrack(0, n);
        return solutions;
    }
};
