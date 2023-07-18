"""
Category: Arrays & Hashing
Idea:     First, transform "nums" to a set so "contains" operations run in
          constant time. The head of a sequences will be a number whose value
          minus 1 will not be in the set. From each sequence head, we can check
          if the next numbers are in the set and build up the sequence.
          Maintain a "max_length" variable that we update and return at the
          very end.
Runtime:  O(N)
"""

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        nums_set = set(nums)
        max_sequence_len = 1
        for num in nums:
            if num - 1 not in nums_set:
                # num is the head of a sequence
                sequence_len = 1
                curr = num + 1 # extend the sequence in the positive direction
                while curr in nums_set:
                    sequence_len += 1
                    curr += 1
                max_sequence_len = max(max_sequence_len, sequence_len)
        return max_sequence_len

