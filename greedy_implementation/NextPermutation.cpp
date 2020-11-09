class Solution {
public:
    bool isDescending(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length - 1; i++) {
            if (nums[i] < nums[i + 1]) return false;
        }
        return true;
    }
    void nextPermutation(vector<int>& nums) {
        if (isDescending(nums)) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int length = nums.size();
        for (int i = length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pair<int, int> best = {i + 1, nums[i + 1]};
                for (int j = i + 1; j < length; j++) {
                    if (nums[j] > nums[i] && nums[j] <= best.second) {
                        best.first = j;
                        best.second = nums[j];
                    }
                }
                swap(nums[i], nums[best.first]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
    }
};
