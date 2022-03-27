class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int jump = 0;
    for (int i = 0; i < n; i++) {
      if (i == n - 1) return true;
      jump = max(jump, nums[i]);
      if (jump == 0) return false;
      jump--;
    }
    return true;
  }
};
