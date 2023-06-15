# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}

# Category: Arrays & Hashing
# Runtime: O(n)
def two_sum(nums, target)
    complements = {}
    i = 0
    while i < nums.length
        if complements.has_key?(nums[i])
            return [complements[nums[i]], i]
        else
            complements[target - nums[i]] = i
        end
        i += 1
    end
    return [-1, -1]
end

