class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = (int) nums.size();
    vector<pair<int, int>> original;
    for (int i = 0; i < n; i++) {
      original.push_back({nums[i], i});
    }
    sort(original.begin(), original.end());
    int l = 0;
    int r = n - 1;
    vector<int> indices;
    while (l < r) {
      int sum = original[l].first + original[r].first;
      if (sum == target) {
        indices = {original[l].second, original[r].second};
        sort(indices.begin(), indices.end());
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
