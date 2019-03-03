class Solution {
public:
    // Brute Force, O(n^2)
    int maxSubArray(vector<int>& nums) {
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