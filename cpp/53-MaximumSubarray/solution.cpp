class Solution {
public:
    // Dynamic Programming, O(n)
    int maxSubArrayDP(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()];
        dp[0] = nums[0];
        int cont_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cont_sum += nums[i];
            if (cont_sum < nums[i]) {  // Should start a new continuous sum.
                cont_sum = nums[i];
            }
            dp[i] = std::max(dp[i - 1], cont_sum);
        }
        return dp[nums.size() - 1];
    }
    // Brute Force, O(n^2)
    int maxSubArrayBF(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = nums[0];
        int current_sum;
        for (int i = 0; i < nums.size(); i++) {
            current_sum = 0;
            for (int j = i; j < nums.size(); j++) {
                current_sum += nums[j];
                if (current_sum > max) {
                    max = current_sum;
                }
            }
        }
        return max;
    }
};