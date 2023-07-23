"""
Idea: Starting from the right, take the bit using the & op.
      Place that bit starting from the left using the | op.
Time: O(1) - This runs 32 times
Space: O(1) - We allocate "res", which is fixed sized.
"""

class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            bit = (n >> i) & 1
            res |= bit << (31 - i)
        return res

