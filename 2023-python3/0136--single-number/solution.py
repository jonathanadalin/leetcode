"""
Idea: Use XOR. Double entries in nums will cancel each other out.
Time: O(n)
Space: O(1)
"""

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res ^= num
        return res

