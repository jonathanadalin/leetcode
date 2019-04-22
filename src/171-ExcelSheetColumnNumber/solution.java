class Solution {
    // O(n) - Go through each character of the string once
    public int titleToNumber(String s) {
        final int shift = 9;
        final int max = 26;
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            num += Math.pow(max, s.length() - i - 1) 
                   * (Character.getNumericValue(s.charAt(i)) - shift);
        }
        return num;
    }
}