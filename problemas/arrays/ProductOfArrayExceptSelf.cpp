class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> left(n + 2, 1);
    vector<int> right(n + 2, 1);
    for (int i = 1; i <= n; i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = n; i >= 1; i--) {
      right[i] = right[i + 1] * nums[i - 1];
    }
    vector<int> products;
    for (int i = 1; i <= n; i++) {
      products.push_back(left[i - 1] * right[i + 1]);
    }
    return products;
  }
};