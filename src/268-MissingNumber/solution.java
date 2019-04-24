class Solution {
    // O(n) - Must go through nums
    public int missingNumber(int[] nums) {
        int nums_sum = 0;
        int all_sum = 0;
        for(int i = 0; i < nums.length; i++) {
            nums_sum += nums[i];
            all_sum += i;
        }
        all_sum += nums.length;
        return all_sum - nums_sum;
    }
}