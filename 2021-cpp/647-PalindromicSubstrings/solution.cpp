class Solution {
public:

    int count = 0;

    // O(n) - Worst case, entire string extended is a palindrome
    void extendPalindrome(const string &s, int left, int right) {
        while(left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
            count++;
            left--;
            right++;
        }
    }  

    // O(n^2) - For loop with 2 * O(n) function calls
    int countSubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        for (int i = 0; i < s.length(); i++) {
            extendPalindrome(s, i, i);      // Odd palindromes
            extendPalindrome(s, i, i + 1);  // Even palindromes
        }
        return count;
    }

    // Below is older solution...

    // O(n) - Worst case, go through <s>
    bool isPalindrome_old(const string &s, int left, int right) {
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

    // O(n^3) - Nested for loop with O(n) call
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