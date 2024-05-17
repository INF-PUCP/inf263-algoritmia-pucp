// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenNumbers;
        for (const int number : nums) {
            if (seenNumbers.count(number) > 0) {
                return true;
            }
            seenNumbers.insert(number);
        }
        return false;
    }
};