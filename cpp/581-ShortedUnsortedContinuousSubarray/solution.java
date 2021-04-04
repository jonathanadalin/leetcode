import java.util.Arrays;

class Solution {
    
    // O(nlog(n))
    // Compare the <nums> with its sorted variant.
    // Pointers from the start and end will indicate
    // parts of <nums> that are already in the right spot.
    // Everything within those pointers needs to be sorted.
    public int findUnsortedSubarray(int[] nums) {
        
        if (nums.length < 2) {
            return 0;  // The array is already sorted.
        }
        
        int[] sorted_nums = new int[nums.length];
        sorted_nums = nums.clone();  // O(n)
        Arrays.sort(sorted_nums);    // O(nlog(n))
        
        int i = 0;
        int j = sorted_nums.length - 1;
        
        // O(n) at worst
        while (i < nums.length) {
            if (nums[i] == sorted_nums[i]) {
                i++;
            } else {
                break;
            }
        }
        
        // O(n) at worst
        while (j > 0 && j > i) {
            if (nums[j] == sorted_nums[j]) {
                j--;
            } else {
                break;
            }
        }
        
        return j - i + 1;  // nums.length - (i + (nums.length - j - 1)) 
    }
}