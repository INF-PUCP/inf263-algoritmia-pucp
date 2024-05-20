// https://leetcode.com/problems/valid-anagram/
class Solution {
private:
    const int ALPHABET_SIZE = 26;
    const int a = int('a');

    vector<int> getFrequencies(const string& s) {
        vector<int> frequencies(ALPHABET_SIZE, 0);
        for (char c : s) {
            frequencies[int(c) - a]++;
        }
        return frequencies;
    }

public:
    bool isAnagram(string s, string t) {
        return getFrequencies(s) == getFrequencies(t);
    }
};