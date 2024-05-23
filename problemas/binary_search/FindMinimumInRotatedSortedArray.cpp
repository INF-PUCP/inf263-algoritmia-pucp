// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.back() >= nums.front()) {
            return nums.front();
        }
        int start = 0;
        int end = int(nums.size()) - 1;
        while (end - start > 1) {
            int mid = (start + end) / 2;
            if (nums[mid] >= nums.front()) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return nums[end];
    }
};