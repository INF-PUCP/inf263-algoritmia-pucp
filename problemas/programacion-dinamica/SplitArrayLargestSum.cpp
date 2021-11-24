class Solution {
public:
  const int INF = 1e9 + 1;
  int len;
  vector<int> prefix_sums;
  
  void GetPrefixSums(const vector<int>& nums) {
    prefix_sums = vector<int>(len);
    prefix_sums[0] = nums[0];
    for (int i = 1; i < len; i++) prefix_sums[i] = prefix_sums[i - 1] + nums[i];
  }
  
  int GetRangeSum(int l, int r) {
    if (l == 0) return prefix_sums[r];
    return prefix_sums[r] - prefix_sums[l - 1];
  }
  
  void Initialize(const vector<int>& nums, int m) {
    // Get the size of the array
    len = (int) nums.size();
    // Precalculate the prefix sums for being used in the DP
    GetPrefixSums(nums);
  }
  
  int splitArray(vector<int>& nums, int m) {
    int n = (int) nums.size();
    Initialize(nums, m);
    // Iterative Dynamic Programming
    vector<int> dp = vector<int>(n, INF);
    // Base case: One block
    dp = prefix_sums;
    // dp(0, i) = min(max(dp(0, j), sum[j + 1 .. r]))
    for (int blocks = 2; blocks <= m; blocks++) {
      vector<int> tmp = vector<int>(n, INF);
      for (int i = blocks - 1; i < n; i++) {
        for (int j = blocks - 2; j < i; j++) {
          tmp[i] = min(tmp[i], max(dp[j], GetRangeSum(j + 1, i)));
        }
      }
      dp = tmp;
    }
    return dp[n - 1];
  }
};