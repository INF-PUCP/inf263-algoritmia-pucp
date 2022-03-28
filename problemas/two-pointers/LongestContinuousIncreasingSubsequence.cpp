// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLenghtOfLCIS(vector<int>& nums) {
        int n = (int) nums.size();
        int lcis = 0;
        int l = 0;
        for (int r = 1; r < n; r++) {
            if (nums[r] <= nums[r - 1]) {
                lcis = max(lcis, r - l);
                l = r;
            }
        }
        lcis = max(lcis, n - l);
        return lcis;
    }
};