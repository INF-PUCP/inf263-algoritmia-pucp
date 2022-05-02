// https://leetcode.com/problems/container-with-most-water/
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = (int)height.size();
    int l = 0;
    int r = n - 1;
    int max_water = 0;
    while (l < r) {
      int water = (r - l) * min(height[l], height[r]);
      max_water = max(max_water, water);
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return max_water;
  }
};