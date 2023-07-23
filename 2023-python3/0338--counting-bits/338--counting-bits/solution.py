"""
Idea: This resolves to a dynamic programming problem.
      The offset increases whenever i reaches offset * 2.
Hint: It helped to draw out the numbers in their binary
      representation.

0 : 0000             offset
1 : 0001               v
2 : 0010 // 1 + dp[i - 2]
3 : 0011 // 1 + dp[i - 2]
4 : 0100 // 1 + dp[i - 4]
5 : 0101 // 1 + dp[i - 4]
6 : 0110 // 1 + dp[i - 4]
7 : 0111 // 1 + dp[i - 4]
8 : 1000 // 1 + dp[i - 8]

Time: O(n)
Space: O(n)
"""

class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0] * (n + 1)
        res[0] = 0
        if n == 0:
            return res
        res[1] = 1
        if n == 1:
            return res
        offset = 1
        for i in range(2, len(res)):
            if offset * 2 == i:
                offset *= 2
            res[i] = 1 + res[i - offset]
        return res

