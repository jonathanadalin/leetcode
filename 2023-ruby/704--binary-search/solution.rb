# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}

# Catogory: Binary search
# Runtime: O(log n)
def search(nums, target)
    return search_with_index(nums, target, 0)
end

def search_with_index(nums, target, index)
    return -1 if nums.length == 0
    if nums.length == 1
        if nums.first == target
            return index
        else
            return -1
        end
    end
        
    middle = nums.length / 2
    left = nums.slice(0, middle)
    right = nums.slice(middle, nums.length)
    if target < nums[middle]
        return search_with_index(left, target, index)
    elsif target > nums[middle]
        return search_with_index(right, target, index + middle)
    else
        return index + middle
    end
end

