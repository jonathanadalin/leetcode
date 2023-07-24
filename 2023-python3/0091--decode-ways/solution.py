"""
Idea: The number of ways we can decode a "123" is:
      A) since "1" is valid, the number of ways we can decode "23"
      B) and since "12" is also valid, add the number of ways we can decode "3".
      That's n = (n + 1) + (n + 2) with certain conditions.
      We can design a dynamic programming solution with that in mind.
Time: O(n)
Space: O(n) - But we can improve to O(1) if we use variables instead of a map for "dp"
"""

class Solution:
    def numDecodings(self, s: str) -> int:
        dp = { len(s) : 1 }
        for i in range(len(s) - 1, -1, -1):
            # Single digit case
            if s[i] == "0":
                dp[i] = 0
            else:
                dp[i] = dp[i + 1]
                # Double digit case
                if i + 1 < len(s) and int(s[i:i + 2]) in range(1, 27):
                    dp[i] += dp[i + 2]
        return dp[0]

