class Solution {
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
}
