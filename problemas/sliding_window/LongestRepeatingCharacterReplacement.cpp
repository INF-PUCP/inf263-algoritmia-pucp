// https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
private:
    const int ALPHABET_SIZE = 26;
    const int A = int('A');

    bool IsValid(const vector<int>& frequencies, const int& k) {
        int maximumFrequency = 0;
        int numberOfCharacters = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            maximumFrequency = max(maximumFrequency, frequencies[i]);
            numberOfCharacters += frequencies[i];
        }
        return numberOfCharacters - maximumFrequency <= k;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> frequencies(ALPHABET_SIZE, 0);
        int stringLength = int(s.size());
        int start = 0;
        int maximumSubstringLength = 0;
        for (int end = 0; end < stringLength; end++) {
            frequencies[int(s[end]) - A]++;
            while (!IsValid(frequencies, k)) {
                frequencies[int(s[start]) - A]--;
                start++;
            }
            int currentSubstringLength = end - start + 1;
            maximumSubstringLength = max(maximumSubstringLength, currentSubstringLength);
        }
        return maximumSubstringLength;
    }
};