// https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        int xor_sum = 0;
        for (int i = 1; i <= n; i++) {
            xor_sum ^= i ^ nums[i - 1];
        }
        return xor_sum;
    }
};