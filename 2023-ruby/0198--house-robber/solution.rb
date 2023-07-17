# @param {Integer[]} nums
# @return {Integer}

# Category: Dynamic Programming
def rob(nums)
    # return rob_recursive(nums, 0) # Too Slow
    return rob_dp(nums, 0, Array.new(nums.length)) # Much better
end

# Runtime: O(N^N) - Works, but we can do better
def rob_recursive(nums, i)
    if i >= nums.length
        return 0
    else
        return [
            nums[i] + rob_recursive(nums, i + 2), # Steal
            rob_recursive(nums, i + 1) # Go next
            ].max
    end
end

# Runtime: O(N)
def rob_dp(nums, i, gains)
    return 0 if i >= nums.length
    if gains[i] == nil
        gains[i] = [
                nums[i] + rob_dp(nums, i + 2, gains), # Steal
                rob_dp(nums, i + 1, gains) # Go next
                ].max
    end
    return gains[i]
end

