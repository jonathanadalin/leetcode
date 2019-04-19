class Solution {
    // O(n)
    public int rob(int[] nums) {
        if (nums.length < 1) {
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        }
        int dp[] = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        // O(n)
        for (int i = 2; i < nums.length; ++i) {
            dp[i] = Math.max(dp[i - 1],             // Don't rob the current house.
                             dp[i - 2] + nums[i]);  // Rob the current house.
        }
        return dp[nums.length - 1];
    }
}