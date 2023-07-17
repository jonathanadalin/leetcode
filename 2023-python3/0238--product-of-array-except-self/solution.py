"""
Category: Arrays & Hashing
Idea:     The product of all elements except nums[i] is the same as multiplying
          the product of the elements preceding i and the product of elements 
          after i. We can calculate each in O(N). To save on memory, we can
          store those products in the resulting array.
Runtime:  O(N) where N is the size of nums
"""

class Solution:

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(len(nums)):
            if i == 0:
                prefix = nums[i]
                result.append(1)
            else:
                result.append(prefix)
                prefix *= nums[i]
        for i in range(len(nums) - 1, -1, -1):
            if i == len(nums) - 1:
                postfix = nums[i]
            else:
                result[i] *= postfix
                postfix *= nums[i]
        return result

    def productExceptSelfOld(self, nums: List[int]) -> List[int]:
        prefixes = [1] * len(nums)
        for i in range(len(nums)):
            if i == 0:
                prefixes[i] = nums[i]
            else:
                prefixes[i] = prefixes[i - 1] * nums[i]
            
        postfixes = [1] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            if i == len(nums) - 1:
                postfixes[i] = nums[i]
            else:
                postfixes[i] = postfixes[i + 1] * nums[i]
        
        result = [0] * len(nums)
        for i in range(len(nums)):
            if i == 0:
                result[i] = postfixes[i + 1]
            elif i == len(nums) -1:
                result[i] = prefixes[i - 1]
            else:
                result[i] = prefixes[i - 1] * postfixes[i + 1]
        
        return result
                
