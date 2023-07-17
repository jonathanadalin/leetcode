# @param {Integer[]} nums
# @return {Integer[][]}

# Category: Backtracking
# Runtime: O(n * 2^n) - There are 2^n subsets, and each subset can be as long 
# as n.
def subsets_with_dup(nums)
    res = []
    build_subsets(nums.sort, res, Set.new, [], 0)
    return res
end

def build_subsets(nums, res, set, curr, i)
    if i >= nums.length
        return if set.include?(curr.to_s)
        res.push(curr.clone)
        set.add(curr.to_s)
        return
    end
    # Include num at index i
    curr.push(nums[i])
    build_subsets(nums, res, set, curr, i + 1)
    curr.pop

    # Skip num at index i
    build_subsets(nums, res, set, curr, i + 1)
end

