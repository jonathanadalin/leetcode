class Solution {
public:
    void permute(vector<int> &nums, int current, vector<vector<int>> &v) {
        if (current == nums.size()) {
            // There is a single permutation for length 1.
            v.push_back(nums);
        } else {
            for (int i = current; i < nums.size(); i++) {
                swap(nums[current], nums[i]);
                permute(nums, current + 1, v);
                // We need to reset for next iteration of for loop
                swap(nums[current], nums[i]);  
            }
        }
    }
    // O(n!) - Runtime is proportional to the number of generated permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permute(nums, 0, v);
        return v;
    }
};