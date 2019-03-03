class Solution {
public:
    // O(n) - Only go through vector once
    int maxProfit(vector<int>& prices) {     
        if (prices.size() < 2) {
            return 0;
        }
        int dp[prices.size()];
        dp[0] = 0;  // No transcations
        dp[1] = std::max(dp[0], prices[1] - prices[0]);
        int min_buy_price = std::min(prices[0], prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            dp[i] = std::max(dp[i - 1], prices[i] - min_buy_price);
            min_buy_price = std::min(prices[i], min_buy_price);
        }
        return dp[prices.size() - 1];
    }
};