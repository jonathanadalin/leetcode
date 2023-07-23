"""
Idea: Binary search with a condition for when the index of the
      target is not found.
Time: O(log n)
Space: O(1)
"""

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)
        while l <= r:
            m = l + (r - l) // 2
            if target == nums[m]:
                return m
            elif target > nums[m]:
                if m == len(nums) - 1 or target < nums[m + 1]:
                    return m + 1
                l = m + 1
            elif target < nums[m]:
                if m == 0 or target > nums[m - 1]:
                    return m
                r = m - 1
        return m

