// https://leetcode.com/problems/word-search/
class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> used;
    
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    
    bool IsValid(int row, int col) {
        return 0 <= row && row < rows && 0 <= col && col < cols;
    }
    
    bool Backtrack(int row, int col, int i, const int n, const vector<vector<char>>& board, const string& word) {
        if (i == n - 1) {
            return board[row][col] == word[i];
        }
        
        if (board[row][col] != word[i]) return false;
        
        bool exists = false;
        for (int j = 0; j < 4; j++) {
            int new_row = row + dx[j];
            int new_col = col + dy[j];
            if (!IsValid(new_row, new_col)) continue;
            if (used[new_row][new_col]) continue;
            used[new_row][new_col] = true;
            exists |= Backtrack(new_row, new_col, i + 1, n, board, word);
            used[new_row][new_col] = false;
        }
        return exists;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = (int)board.size();
        cols = (int)board[0].size();
        used = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int word_size = (int)word.size();
        
        bool exists = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                used[i][j] = true;
                exists |= Backtrack(i, j, 0, word_size, board, word);
                used[i][j] = false;
                if (exists) break;
            }
            if (exists) break;
        }
        return exists;
    }
};
