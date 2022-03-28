class Solution {
public:
    int getLen(pair<int, int> interval) {
        return (interval.second - interval.first + 1);
    }
    
    pair<int, int> getMax(int center, string& s) {
        pair<int, int> best = {center, center};
        int len = 1;
        while (center - len >= 0 && center + len < s.size()) {
            int left = center - len;
            int right = center + len;
            if (s[left] == s[right]) {
                best = {left, right};
                len++;
            } else {
                break;
            }
        }
        len = 1;
        while (center - len + 1 >= 0 && center + len < s.size()) {
            int left = center - len + 1;
            int right = center + len;
            if (s[left] == s[right]) {
                pair<int, int> candidate = {left, right};
                if (getLen(candidate) > getLen(best)) best = candidate;
                len++;
            } else {
                break;
            }
        }
        return best;
    }
    
    string longestPalindrome(string s) {
        int len = s.size();
        pair<int, int> best = {0, 0};
        for (int i = 0; i < len; i++) {
            pair<int, int> current = getMax(i, s);
            if (getLen(current) > getLen(best)) best = current;
        }
        return s.substr(best.first, getLen(best));
    }
};
