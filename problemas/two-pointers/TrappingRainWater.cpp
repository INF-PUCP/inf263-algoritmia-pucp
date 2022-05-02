// https://leetcode.com/problems/trapping-rain-water/
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = (int)height.size();

    int left_border, right_border;
    left_border = right_border = 0;

    int l = 0;
    int r = n - 1;

    int water = 0;

    while (l < r) {
      left_border = max(left_border, height[l]);
      right_border = max(right_border, height[r]);
      int border = min(left_border, right_border);
      int add = 0;
      if (height[l] < height[r]) {
        add = max(0, border - height[l]);
        l++;
      } else {
        add = max(0, border - height[r]);
        r--;
      }
      water += add;
    }
    return water;
  }
};