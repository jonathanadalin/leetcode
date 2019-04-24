class Solution {
    
    // O(2n) - Go through s twice at most.
    public int firstUniqChar(String s) {
        int[] freq = new int[26];  // 26 letters in alphabet.
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (freq[s.charAt(i) - 'a'] == 1) {
                return i;   
            }
        }
        return -1;  //  All letters have duplicates.
    }
    
    
    public int firstUniqCharHashMap(String s) {
        HashMap<Character, Integer> hm = new HashMap();
        for (int i = 0; i < s.length(); i++) {
            if (hm.containsKey(s.charAt(i))) {
                hm.replace(s.charAt(i), hm.get(s.charAt(i)) + 1);
            } else {
                hm.put(s.charAt(i), 0);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (hm.get(s.charAt(i)) == 0) {
                return i;
            }
        }
        return -1;
    }
    
}