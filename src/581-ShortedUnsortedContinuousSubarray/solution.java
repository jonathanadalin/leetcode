import java.util.Arrays;

class Solution {
    
    public int findUnsortedSubarray(int[] nums) {
        
        // The array is already sorted.
        if (nums.length < 2) {
            return 0;
        }
        
        int[] sorted_nums = new int[nums.length];
        sorted_nums = nums.clone();
        Arrays.sort(sorted_nums);
        
        int i = 0;
        int j = sorted_nums.length - 1;
        
        while (i < nums.length) {
            if (nums[i] == sorted_nums[i]) {
                i++;
            } else {
                break;
            }
        }
        
        while (j > 0 && j > i) {
            if (nums[j] == sorted_nums[j]) {
                j--;
            } else {
                break;
            }
        }
        
        return nums.length - (i + nums.length - j - 1); 
    }
}