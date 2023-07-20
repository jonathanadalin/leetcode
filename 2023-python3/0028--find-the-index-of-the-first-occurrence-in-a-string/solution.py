"""
Idea:  Traverse the haystack checking if substrings of needle's
       length match the needle.
Time:  O(n) where n is the length of the haystack string
Space: O(1) - we only have an int variable for i
"""

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i = 0
        while i < len(haystack) - len(needle) + 1:
            if haystack[i: i + len(needle)] == needle:
                return i
            i += 1
        return -1

