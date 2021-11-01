const int INF = 1e5;

class Solution {
private:
  vector<vector<int>> dp;
  vector<vector<bool>> is_done;

public:
  int DP(int amount, int position, const vector<int>& coins) {
    if (amount < 0) return INF;
    if (amount == 0) return 0;
    if (position == coins.size()) {
      if (amount == 0) return 0;
      return INF;
    }
    if (is_done[amount][position]) return dp[amount][position];
    dp[amount][position] = min(DP(amount, position + 1, coins), 1 + DP(amount - coins[position], position, coins));
    is_done[amount][position] = true;
    return dp[amount][position];
  }

  int coinChange(vector<int>& coins, int amount) {
    dp.clear();
    is_done.clear();
    int n = coins.size();
    dp.resize(amount + 1, vector<int> (n, 0));
    is_done.resize(amount + 1, vector<bool> (n, false));
    int minimum = DP(amount, 0, coins);
    if (minimum >= INF) return -1;
    return minimum;
  }
};
