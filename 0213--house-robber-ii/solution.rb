# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
    return 0 if nums.length == 0
    return nums[0] if nums.length == 1
    return [rob_recursive(nums, 1, 0), rob_recursive(nums, 0, 1)].max
end

def rob_recursive(nums, i, tail)
    return 0 if i >= nums.length - tail
        
    return [nums[i] + rob_recursive(nums, i + 2, tail),
            rob_recursive(nums, i + 1, tail)].max
end

