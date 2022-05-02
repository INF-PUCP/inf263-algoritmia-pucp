// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = (int)numbers.size();
    int l = 0;
    int r = n - 1;
    vector<int> indices = {-1, -1};
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum == target) {
        indices = {l + 1, r + 1};
        break;
      }
      if (sum < target) {
        l++;
      } else {
        r--;
      }
    }
    return indices;
  }
};