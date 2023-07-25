"""
Idea: Dynamic programming where the "dp" cache at a given index 
      represents the number of coins needed to make up an "amount" of value index.
      We first initialize the "dp" array to -1 and for each coin, we set dp[coin] to 1.
      We then build up the cache and return the requested value, dp[amount].
Time: O(m * amount) where m is the size of coins
Space: O(amount)
"""

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1] * (amount + 1)
        dp[0] = 0
        for coin in coins:
            if coin <= amount:
                dp[coin] = 1
        
        for curr in range(amount + 1):
            for coin in coins:
                before = curr - coin
                if before >= 0 and dp[before] != -1:
                    if dp[curr] == -1:
                        dp[curr] = 1 + dp[before]
                    else:
                        dp[curr] = min(dp[curr], 1 + dp[before])
        
        return dp[amount]

