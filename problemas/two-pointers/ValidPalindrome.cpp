// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString;
        for (char c : s) {
            if (isalnum(c)) {
                cleanString += tolower(c);
            }
        }
        int n = int(cleanString.size());
        for (int i = 0; i < n / 2; i++) {
            if (cleanString[i] != cleanString[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};