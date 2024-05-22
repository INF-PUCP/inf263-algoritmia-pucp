// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int minimumIndex = 0;
        for (int rightIndex = 0; rightIndex < (int)prices.size(); rightIndex++) {
            if (prices[rightIndex] < prices[minimumIndex]) {
                minimumIndex = rightIndex;
            }
            int currentMaximumProfit = prices[rightIndex] - prices[minimumIndex];
            maximumProfit = max(maximumProfit, currentMaximumProfit);
        }
        return maximumProfit;
    }
};