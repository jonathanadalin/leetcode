# Runtime: O(n 2^n)
# Category: Backtracking
# Reasoning: 
# The brute force solution is most optimal. It helps to think of building
# subsets consists of making the decision of including an entry or num or not.
#
# eg.
# With nums = [1, 2, 3]
# The [] subset is equivalent to [no, no, no]
# The [1, 2] subset is equivalent to [yes, yes, no]

# @param {Integer[]} nums
# @return {Integer[][]}
def subsets(nums)
    res = []
    curr = []
    i = 0
    dfs(nums, res, curr, i)
    return res
end

def dfs(nums, res, curr, i)
    if i == nums.length
        # Making a copy is important
        res.push(curr.clone)
        return
    end

    # Taking the value
    curr.push(nums[i])
    dfs(nums, res, curr, i + 1)
    
    # Don't take the value
    curr.pop
    dfs(nums, res, curr, i + 1)
end

