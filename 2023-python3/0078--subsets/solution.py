"""
Idea: This is a backtracking problem.
      Make two recursive calls when building up subsets.
      The first should include the number at index i, and
      the next should omit it.
      Add to the resulting array when the index i is at
      length of nums.
Time: O(n * 2 ^ n) - There are 2^n subsets, up to length n
Space: O(2 * 2 ^ n)
"""

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        curr = []
        def build_subsets(i = 0):
            if i == len(nums):
                result.append(curr.copy())
                return
            curr.append(nums[i])
            build_subsets(i + 1) # include the number
            curr.pop()
            build_subsets(i + 1) # don't include

        build_subsets()
        return result

