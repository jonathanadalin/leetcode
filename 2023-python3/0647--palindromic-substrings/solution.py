"""
Idea: For each character, extend the substring and increment
      our count for each valid palindrome.
      Palindromes can be odd or even length.
Time: O(n ^ 2) - Palindromes can be as long as the input string.
Space: O(1)
"""

class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s)):
            # Odd length substrings
            l = i
            r = i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1
            # Even length substrings
            l = i
            r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1
        return count

