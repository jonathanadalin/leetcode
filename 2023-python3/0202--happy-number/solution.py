"""
Category: Math & Geometry
Idea:     Use a set to detect the cycle
"""

class Solution:
    def isHappy(self, n: int) -> bool:
        values_so_far = set()
        curr = n
        while curr not in values_so_far:
            values_so_far.add(curr)
            n = 0
            for c in str(curr):
                n += int(c) ** 2
            if n == 1:
                return True
            curr = n
        return False

