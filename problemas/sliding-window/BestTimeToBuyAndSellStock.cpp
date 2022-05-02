class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n_prices = (int)prices.size();
    int max_profit = 0;
    vector<int> right_max(n_prices);
    right_max[n_prices - 1] = prices[n_prices - 1];
    for (int i = n_prices - 2; i >= 0; i--) {
      right_max[i] = max(right_max[i + 1], prices[i]);
    }
    for (int i = 0; i < n_prices - 1; i++) {
      max_profit = max(max_profit, right_max[i + 1] - prices[i]);
    }
    return max_profit;
  }
};