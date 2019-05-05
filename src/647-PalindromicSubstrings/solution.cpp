class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s.at(left) == s.at(right)) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int left = 0; left < s.length(); left++ ) {
            for (int right = left; right < s.length(); right++) {
                if (isPalindrome(s, left, right)) {
                    count++;
                }
            }
        }
        return count;
    }
};