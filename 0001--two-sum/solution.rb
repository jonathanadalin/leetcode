"""
Category: Arrays & Hashing
Idea:     Maintain a map of complements to the target that we can fetch
          to build the result
Runtime:  O(N) where N is the size of nums
"""
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complements = {}
        for i in range(len(nums)):
            num = nums[i]
            if num in complements:
                return [complements[num], i]
            else:
                complements[target - num] = i
        return [-1, -1]

