"""
Idea: Use binary search because it's better than the brute
      force O(sqrt(n)) solution.
Time: O(logn)
Space: O(1)
"""

class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        l, r = 0, x
        while True:
            m = l + (r - l) // 2
            if m > x / m:
                r = m - 1
            else:
                if m + 1 > x / (m + 1):
                    return m
                l = m + 1

