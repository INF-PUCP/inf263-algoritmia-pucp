// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
private:
    int findMinimumIndex(const vector<int>& nums) {
        if (nums.back() >= nums.front()) {
            return 0;
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
        return end;
    }

public:
    int BinarySearch(
        int target,
        const vector<int>& numbers,
        int start,
        int end
    ) {
        if (start > end) {
            return -1;
        }

        if (numbers[start] > target) {
            return -1;
        }

        if (numbers[end] <= target) {
            if (numbers[end] == target) {
                return end;
            }
            return -1;
        }

        while (end - start > 1) {
            int mid = (start + end) / 2;
            if (numbers[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (numbers[start] == target) {
            return start;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int minimumIndex = findMinimumIndex(nums);
        if (nums[minimumIndex] == target) {
            return minimumIndex;
        }
        int targetIndex = max(
            BinarySearch(target, nums, 0, minimumIndex - 1),
            BinarySearch(target, nums, minimumIndex + 1, int(nums.size()) - 1)
        );
        return targetIndex;
    }
};