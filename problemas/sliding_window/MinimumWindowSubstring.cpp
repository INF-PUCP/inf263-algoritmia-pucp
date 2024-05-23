// https://leetcode.com/problems/minimum-window-substring/
class Solution {
private:
    const int ALPHABET_SIZE = 58;
    const int ASCII_A = int('A');
    const pair<int, int> EMPTY = make_pair(-1, -1);

    bool Contains(const vector<int>& sourceFrequencies, const vector<int>& targetFrequencies) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (sourceFrequencies[i] < targetFrequencies[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        vector<int> sourceFrequencies(ALPHABET_SIZE, 0);
        vector<int> targetFrequencies(ALPHABET_SIZE, 0);
        for (char c : t) {
            targetFrequencies[int(c) - ASCII_A]++;
        }

        int start = 0;
        int sourceLength = int(s.size());
        pair<int, int> window = EMPTY;
        for (int end = 0; end < sourceLength; end++) {
            sourceFrequencies[int(s[end]) - ASCII_A]++;

            while (start < end) {
                if (!Contains(sourceFrequencies, targetFrequencies)) {
                    break;
                }
                sourceFrequencies[int(s[start]) - ASCII_A]--;
                if (Contains(sourceFrequencies, targetFrequencies)) {
                    start++;
                } else {
                    sourceFrequencies[int(s[start]) - ASCII_A]++;
                    break;
                }
            }

            if (
                Contains(sourceFrequencies, targetFrequencies) &&
                (window == EMPTY || end - start < window.second - window.first)
            ) {
                window = make_pair(start, end);
            }
        }

        if (window == EMPTY) {
            return "";
        }

        return s.substr(window.first, window.second - window.first + 1);
    }
};