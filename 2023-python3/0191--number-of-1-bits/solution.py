"""
Idea: Use the modulo operator to very if the trailing bit was a 1.
Time: O(1) - This runs at most 32 times.
Space: O(1) - We only store the variable for "count".
"""

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            if n % 2 == 1:
                count += 1
            n //= 2
        return count

