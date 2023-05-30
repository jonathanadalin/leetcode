class Solution {
  public:
    // O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement_indexes;
        // O(n) - single pass
        for (int i = 0; i< nums.size(); i++) {
            // We can't use the same element twice so we only add to the map at
            // the end.
            // O(1) - unordered map search
            if (complement_indexes.find(nums[i]) != complement_indexes.end()) {
                return {i, complement_indexes[nums[i]]};
            }
            // O(1) - unordered map insert
            complement_indexes[target - nums[i]] = i;
        }
        return {}; // No match found
    }

    // O(n^2)
    vector<int> twoSumSlow(vector<int>& nums, int target) {
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

