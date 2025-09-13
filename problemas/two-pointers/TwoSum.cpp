// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n{(int)nums.size()};
        std::vector<std::pair<int, int>> sorted_nums;
        for (int i = 0; i < n; i++) {
            sorted_nums.push_back({nums[i], i});
        }
        std::sort(sorted_nums.begin(), sorted_nums.end());
        int L{0};
        int R{n - 1};
        while (L < R) {
            int sum{sorted_nums[L].first + sorted_nums[R].first};
            if (sum == target) {
                return {sorted_nums[L].second, sorted_nums[R].second};
            } else if (sum < target) {
                L++;
            } else {
                R--;
            }
        }
        return {-1, -1};
    }
};
