class Solution {
private:
  vector<vector<int>> dp;
  vector<vector<bool>> is_done;
public:
  int DP(int amount, int position, const vector<int>& coins) {
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    if (position == coins.size()) return 0;
    if (is_done[amount][position]) return dp[amount][position];
    dp[amount][position] = DP(amount, position + 1, coins) + DP(amount - coins[position], position, coins);
    is_done[amount][position] = true;
    return dp[amount][position];
  }

  int change(int amount, const vector<int>& coins) {
    int n = coins.size();
    dp.resize(amount + 1, vector<int> (n, 0));
    is_done.resize(amount + 1, vector<bool> (n, false));
    return DP(amount, 0, coins);
  }
};
