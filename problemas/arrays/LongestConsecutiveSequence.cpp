// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
 private:
  unordered_set<int> found;
  unordered_map<int, int> dp;

 public:
  int DP(int num) {
    if (dp.count(num) > 0) return dp[num];
    dp[num] = 1;
    if (found.count(num + 1) > 0) {
      dp[num] += DP(num + 1);
    }
    return dp[num];
  }

  int longestConsecutive(vector<int>& nums) {
    for (int num : nums) {
      found.insert(num);
    }
    int mx = 0;
    for (int num : nums) {
      mx = max(mx, DP(num));
    }
    return mx;
  }
};