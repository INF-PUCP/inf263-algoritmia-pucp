// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
private:
    unordered_set<int> found;
    unordered_map<int, int> sequenceLength;

    int FindLongestSequenceLength(int end) {
        if (found.count(end) == 0) return 0;
        if (sequenceLength.count(end) > 0) return sequenceLength[end];
        sequenceLength[end] = 1 + FindLongestSequenceLength(end - 1);
        return sequenceLength[end];
    }

public:
    int longestConsecutive(vector<int>& numbers) {
        for (int number : numbers) {
            found.insert(number);
        }
        int longestSequenceLength = 0;
        for (int number : numbers) {
            longestSequenceLength = max(longestSequenceLength, FindLongestSequenceLength(number));
        }
        return longestSequenceLength;
    }
};
