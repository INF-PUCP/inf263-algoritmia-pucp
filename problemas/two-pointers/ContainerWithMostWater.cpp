// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmountOfWater = 0;
        int left = 0;
        int right = int(heights.size()) - 1;
        while (left <= right) {
            int currentAmountOfWater = (right - left) * (min(heights[left], heights[right]));
            maxAmountOfWater = max(maxAmountOfWater, currentAmountOfWater);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxAmountOfWater;
    }
};