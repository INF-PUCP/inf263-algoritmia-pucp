// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<vector<int>> letters;
    vector<string> combinations;
    string combination;
    
    void Backtrack(int i, int n, const string& digits) {
        if (i == n) {
            combinations.push_back(combination);
            return;
        }
        int digit = digits[i] - '2';
        for (int offset : letters[digit]) {
            combination.push_back((char)('a' + offset));
            Backtrack(i + 1, n, digits);
            combination.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        int offset = 0;
        for (int i = 2; i <= 9; i++) {
            int cnt = 3;
            if (i == 7 || i == 9) cnt++;
            vector<int> current_letters;
            for (int j = 0; j < cnt; j++) {
                current_letters.push_back(offset);
                offset++;
            }
            letters.push_back(current_letters);
        }
        int n = (int)digits.size();
        Backtrack(0, n, digits);
        return combinations;
    }
};
