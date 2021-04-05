/**
* Given a non-empty array of integers nums, every element appears twice except for
* one. Find that single one.
*/

class Solution {
    public int singleNumber(int[] nums) {
        var val = 0;
        for (var num : nums) {
            // XOR returns true iff the operands are different.
            val ^= num;
        }
        return val;
    }
}
