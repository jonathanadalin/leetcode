class Solution {
    // O(n) - We go through nums once.
    public boolean containsDuplicate(int[] nums) {
        HashSet hs = new HashSet();
        for (int i = 0; i < nums.length; ++i) {
            // O(1) - Check if hash has a value.
            if (hs.contains(nums[i])) {
                return true;
            } else {
                hs.add(nums[i]);
            }
        }
        return false;
    }
}