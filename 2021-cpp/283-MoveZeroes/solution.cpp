// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.

class Solution {
public:
    // O(n) since our indexes span the size of <nums> once each.
    void moveZeroes(vector<int>& nums) {
        int non_zero_index = 0;
        int all_elem_index = 0;
        while (all_elem_index < nums.size()) {
            if (nums[all_elem_index] != 0) {
                nums[non_zero_index] = nums[all_elem_index];
                non_zero_index++;  // Only iterate if non-zero value.
            }
            all_elem_index++;
        }
        // The rest of the values are 0s.
        while (non_zero_index < nums.size()) {
            nums[non_zero_index] = 0;
            non_zero_index++;
        }
    }
};