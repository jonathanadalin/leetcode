"""
Idea: We can use XOR. Double entries cancel out. The missing number
      will surface after XOR'ing nums against the expected range.
Time: O(n)
Space: O(1)
"""
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = 0
        for i in range(len(nums) + 1):
            n ^= i
        for num in nums:
            n ^= num
        return n

    """
    Idea: Approach using hashing that we can improve on space wise.
    Time: O(n)
    Space: O(n)
    """
    def missingNumberWithSets(self, nums: List[int]) -> int:
        s = set()
        for i in range(len(nums) + 1):
            s.add(i)
        for num in nums:
            s.remove(num)
        return s.pop()

