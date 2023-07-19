"""
Category: Math & Geometry
Idea:     Convert to an integer, increment, then convert back
Runtime:  O(N) where N is the length of digits
"""

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        plus_one = 0
        for i, v in enumerate(digits):
            base_ten_multiplier = len(digits) - i - 1
            plus_one += v * 10 ** base_ten_multiplier
        plus_one += 1
        plus_one = str(plus_one)
        result = [0] * len(plus_one)
        for i in range(len(result)):
            result[i] = int(plus_one[i])
        return result

