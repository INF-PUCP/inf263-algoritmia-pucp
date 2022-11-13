// https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<bool>> is_palindrome;
    vector<vector<string>> partitions;
    vector<string> s_partition;
    vector<int> partition_sizes;
    
    void Backtrack(int i, int n, const string& s) {
        if (i == n) {
            int j = 0;
            for (int sz : partition_sizes) {
                s_partition.push_back(s.substr(j, sz));
                j += sz;
            }
            partitions.push_back(s_partition);
            s_partition.clear();
            return;
        }
        int len = n - i;
        for (int sz = 1; sz <= len; sz++) {
            if (!is_palindrome[i][i + sz - 1]) continue;
            partition_sizes.push_back(sz);
            Backtrack(i + sz, n, s);
            partition_sizes.pop_back();
        }
    }
    
    bool IsPalindrome(int i, int j, const string& s) {
        int len = j - i + 1;
        for (int k = 0; k < len / 2; k++) {
            if (s[i + k] != s[j - k]) return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        is_palindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                is_palindrome[i][j] = IsPalindrome(i, j, s);
            }
        }
        Backtrack(0, n, s);
        return partitions;
    }
};
