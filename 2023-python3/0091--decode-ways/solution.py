"""
Idea: The number of ways we can decode a "123" is:
      A) since "1" is valid, the number of ways we can decode "23"
      B) and since "12" is also valid, add the number of ways we can decode "3".
      That's n = (n + 1) + (n + 2) with certain conditions.
      We can design a dynamic programming solution with that in mind.
Time: O(n)
Space: O(1)
"""

class Solution:
    # Use variables to reduce space complexity.
    def numDecodings(self, s: str) -> int:
        next_one = 1
        one_before = next_one
        two_before = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "0":
                next_one = 0
            else:
                next_one = one_before
                if i + 1 < len(s) and int(s[i:i + 2]) in range(0, 27):
                    next_one += two_before
            two_before = one_before
            one_before = next_one
        return next_one

    def numDecodingsWithMap(self, s: str) -> int:
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

