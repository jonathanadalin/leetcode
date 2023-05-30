class Solution {
public:
    // O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n)
        for (int i = 0; i < nums.size() - 1; i++) {
            // O(n)
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

