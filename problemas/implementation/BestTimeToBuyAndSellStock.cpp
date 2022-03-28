// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n_prices = (int) prices.size();
        int max_stock = prices[n_prices - 1];
        int max_profit = 0;
        for (int day = n_prices - 2; day >= 0; day--) {
            int stock = prices[day];
            max_profit = max(max_profit, max_stock - stock);
            max_stock = max(max_stock, stock);
        }
        return max_profit;        
    }
};