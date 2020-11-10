class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> odd;
    for (int i = 0; i < n; i++) {
      if (nums[i] & 1) {
        odd.push_back(i);
      }
    }

    int result = 0;
    int len = odd.size();
    for (int i = 0; i <= len - k ; i++) {
      int left = (i == 0) ? (odd[i] + 1) : (odd[i] - odd[i - 1]);
      int j = i + k - 1;
      int right = (j == (len - 1)) ? (n - odd[j]) : (odd[j + 1] - odd[j]);
      result += (left * right);
    }
    return result;
  }
};
