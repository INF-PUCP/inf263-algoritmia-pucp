class Solution {
   public:
    const char ASTERIK = '*';
    const char DOT = '.';
    const int ALPHABET = 27;
    int n_word, n_pattern;
    vector<int> word, pattern;
    vector<vector<bool>> done, dp;

    int GetValue(const char& c) {
        if (c == DOT) return ALPHABET - 1;
        return c - 'a';
    }

    vector<int> Transform(const string& s) {
        vector<int> result;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            int value = GetValue(s[i]);
            if (i < n - 1 && s[i + 1] == ASTERIK) {
                result.push_back(value + ALPHABET);
                i++;
            } else {
                result.push_back(value);
            }
        }
        return result;
    }

    void Initialize(const string& s, const string& p) {
        word = Transform(s);
        pattern = Transform(p);
        n_word = (int)word.size();
        n_pattern = (int)pattern.size();
        done = vector<vector<bool>>(n_word + 1, vector<bool>(n_pattern, false));
        dp = vector<vector<bool>>(n_word + 1, vector<bool>(n_pattern, false));
    }

    // DP(i, j): Is it possible to match the substring word[i .. n_word - 1]
    // with the regex expression pattern[j .. n_pattern - 1]?
    bool DP(int i, int j) {
        if (i == n_word && j == n_pattern) return true;
        if (j == n_pattern) return false;
        if (done[i][j]) return dp[i][j];
        if (i == n_word) {
            if (pattern[j] >= ALPHABET) {
                dp[i][j] = DP(i, j + 1);
            }
        } else {
            if (pattern[j] >= ALPHABET) {
                dp[i][j] = DP(i, j + 1);
                if (pattern[j] == 2 * ALPHABET - 1 || pattern[j] == word[i] + ALPHABET) {
                    dp[i][j] = dp[i][j] || DP(i + 1, j);
                }
            } else {
                if (pattern[j] == ALPHABET - 1 || pattern[j] == word[i]) {
                    dp[i][j] = DP(i + 1, j + 1);
                }
            }
        }
        done[i][j] = true;
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        Initialize(s, p);
        return DP(0, 0);
    }
};