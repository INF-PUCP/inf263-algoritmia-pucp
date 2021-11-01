class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int left, right;
    left = right = -1;
    vector<int> copy = nums;
    sort(copy.begin(), copy.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] != copy[i]) {
        if (left == -1) {
          left = right = i;
        } else {
          right = i;
        }
      }
    }
    if (left == -1) return 0;
    return (right - left + 1);
  }
};
