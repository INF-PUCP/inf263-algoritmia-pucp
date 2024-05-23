// https://leetcode.com/problems/valid-parentheses/
class Solution {
private:
    map<char, char> closings;

public:
    Solution() {
        closings['{'] = '}';
        closings['['] = ']';
        closings['('] = ')';
    }

    bool isValid(string s) {
        stack<char> openings;
        for (char c : s) {
            if (closings.count(c) > 0) {
                openings.push(c);
            } else {
                if (openings.empty() || closings[openings.top()] != c) {
                    return false;
                }
                openings.pop();
            }
        }
        return openings.empty();
    }
};