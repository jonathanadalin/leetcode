class Solution {
    // O(n) - We iterate through prices once
    //
    // The net sum of all the profits is equal to
    // to the optimal purchase and sell order gain.
    // 
    // You can compare this to calculating the distance
    // between two points with intermediate points
    // 
    // eg.
    // a .. b .. c .. d
    // The distance a to d, |ad|, is the same as
    // |ab| + |bc| + |cd|
    public int maxProfit(int[] prices) {
        if (prices.length < 2) {
            return 0;
        }
        int profit = 0;
        for (int i = 0; i < prices.length - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                profit += (prices[i + 1] - prices[i]);
            }
        }
        return profit;
    }
}