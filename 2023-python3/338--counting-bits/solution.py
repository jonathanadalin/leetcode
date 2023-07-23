"""
Idea: Convert each number into its binary representation then count
Time: O(n)
Space: O(n)
"""

class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0] * (n + 1)
        for i in range(len(res)):
            count = 0
            for c in str(bin(i)[2:]): # At most 32 times
                if c == '1':
                    count += 1
            res[i] = count
        return res

