class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    int length = nums.size();
    for (int i = 0; i < length - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int a = nums[i];
      int target = -nums[i];
      int left = i + 1;
      int right = length - 1;
      while (left < right) {
        int b = nums[left];
        int c = nums[right];
        if (b + c < target) {
          left++;
          continue;
        }
        if (b + c > target) {
          right--;
          continue;
        }
        vector<int> current = {a, b, c};
        result.push_back(current);
        // b + c == target
        while (left < right && nums[left] == b) left++;
        while (right > left && nums[right] == c) right--;
      }
    }
    return result;
  }
};
