class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) {
            return 0;
        }
        int i = 1;
        int min = prices[0];
        int profit = 0;
        while (i < prices.length - 1) {
            if (prices[i] > prices[i - 1]) {
                // Sell!
                profit += prices[i] - min;
                min = prices[i + 1];
                i++;
            } else {
                min = prices[i];
            }
            i++;
        }
        return profit;
    }
}