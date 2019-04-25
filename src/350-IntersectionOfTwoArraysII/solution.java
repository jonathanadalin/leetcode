class Solution {
    // O(n + m) - Go through both input arrays
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hm = new HashMap();
        for (int i = 0; i < nums1.length; i++) {
            if (hm.containsKey(nums1[i])) {
                hm.replace(nums1[i], hm.get(nums1[i]) + 1);
            } else {
                hm.put(nums1[i], 1);
            }
        }
        ArrayList<Integer> al = new ArrayList();
        for (int i = 0; i < nums2.length; i++) {
            int key = nums2[i];
            if (hm.containsKey(key)) {
                if (hm.get(key) > 0) {
                    hm.replace(key, hm.get(key) - 1);
                    al.add(key);
                }
            }
        }
        int[] intersect_array = new int[al.size()];
        for (int i = 0; i < al.size(); i++) {
            intersect_array[i] = al.get(i);
        }
        return intersect_array;
    }
}