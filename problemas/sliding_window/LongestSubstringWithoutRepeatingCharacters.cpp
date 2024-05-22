// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
private:
    const int ALPHABET_SIZE = 256;

    bool HasRepeatingCharacters(const vector<int>& frequencies) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (frequencies[i] > 1) {
                return true;
            }
        }
        return false;
    }

public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = int(s.size());
        int longestSubstringLength = 0;
        int start = 0;
        vector<int> frequencies(ALPHABET_SIZE, 0);
        for (int end = 0; end < stringLength; end++) {
            frequencies[int(s[end])]++;
            while (HasRepeatingCharacters(frequencies)) {
                frequencies[int(s[start])]--;
                start++;
            }
            int currentLongestSubstringLength = end - start + 1;
            longestSubstringLength = max(longestSubstringLength, currentLongestSubstringLength);
        }
        return longestSubstringLength;
    }
};