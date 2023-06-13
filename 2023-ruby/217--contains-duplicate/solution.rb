# @param {Integer[]} nums
# @return {Boolean}

# Category: Arrays & Hashing
# Runtime: O(n)
def contains_duplicate(nums)
    set = Set.new([])
    for num in nums
        return true if set.include?(num)
        set.add(num)
    end
    return false
end

