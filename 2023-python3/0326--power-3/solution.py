"""
Idea: Compare n to the powers of three.
Time: O(log n)
Space: O(1)
"""

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        power_3 = 1
        while power_3 <= n:
            if power_3 == n:
                return True
            power_3 *= 3
        return False

