/**
* Given a non-empty array of integers nums, every element appears twice except for
* one. Find that single one.
*/

class Solution {
    public int singleNumber(int[] nums) {
        var set = new HashSet<Integer>();
        var val = 0;
        // This approach can overflow.
        for (var num : nums) {
            if (set.contains(num)) {
                set.remove(num);
                val -= num;
            } else {
                set.add(num);
                val += num;
            }
        }
        return val;
    }
}
