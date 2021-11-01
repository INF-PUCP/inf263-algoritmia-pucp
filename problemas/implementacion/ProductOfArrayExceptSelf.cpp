class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = num.size();
    vector<int> left;
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        left.push_back(nums[i]);
      } else {
        left.push_back(nums[i] * left[i - 1]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        right[i] = nums[i];
      } else {
        right[i] = nums[i] * right[i + 1];
      }
    }
    vector<int> answer;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        answer.push_back(right[i + 1]);
      } else {
        if (i == n - 1) {
          answer.push_back(left[i - 1]);
        } else {
          answer.push_back(left[i - 1] * right[i + 1]);
        }
      }
    }
    return answer;
  }
};
