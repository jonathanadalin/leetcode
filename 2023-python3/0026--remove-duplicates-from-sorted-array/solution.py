"""
Idea:  Loop through nums and use a set to check for duplicates
       The size of the growing set is the number of unique numbers
Time:  O(n) where n is the length of nums
Space: O(n) where n is the number of unique numbers
"""

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        s = set()
        i = 0
        for num in nums:
            if num not in s:
                s.add(num)
                nums[i] = num
                i += 1
        return len(s)

