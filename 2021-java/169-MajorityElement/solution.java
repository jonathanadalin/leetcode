/**
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You
 * may assume that the majority element always exists in the array.
 */

class Solution {

    // log(N)
    public int majorityElement(int[] nums) {
        var countMap = new HashMap<Integer, Integer>();
        for (var num : nums) {
            if (countMap.containsKey(num)) {
                countMap.put(num, 1 + countMap.get(num));
            } else {
                countMap.put(num, 1);
            }
        }
        // Assume at least input at least size 1.
        var majorityElement = nums[0];
        for (var countEntry : countMap.entrySet()) {
            if (countEntry.getValue() > countMap.get(majorityElement)) {
                majorityElement = countEntry.getKey();
            }
        }
        return majorityElement;
    }

    /**
     * Boyer-Moore Voting Algorithm
     * It is impossible to discard subsections where there are more majority
     * elements than minority elements when count equals 0. We can discard
     * that subsection and solve for the remaining recursively.
     */
    public int majorityElementBoyerMoore(int[] nums) {
        var candidate = nums[0]; // Assume at least size 1 list.
        var count = 0;
        for (var num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count = (num == candidate)? count + 1 : count - 1;
        }
        return candidate;
    }
}
