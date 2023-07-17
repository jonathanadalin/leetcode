"""
Category: Arrays & Hashing
Idea:     First create a lookup table of the numbers and their frequencies.
          Next, build up a max heap from that table so pops return the largest
          frequency numbers. We can use that to build our result.
Runtime:  O(N log N) where N is the size of nums
"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequencies = {}
        # O(N)
        for num in nums:
            if num in frequencies:
                frequencies[num] += 1
            else:
                frequencies[num] = 1

        # O(N * log N)
        min_heap = []
        for num, frequency in frequencies.items():
            # Invert the value so pop returns the largest value.
            heappush(min_heap, (frequency * -1, num))  # log N

        # O (k * log N)
        result = []
        for i in range(k):
            result.append(heappop(min_heap)[1])  # log N

        return result

