# @param {Integer[]} nums
# @return {Integer[][]}

# Category: Backtracking
# Runtime: O(N!)
def permute(nums)
    res = []
    generate_permutations(nums, res, [])
    return res
end

def generate_permutations(nums, res, curr)
    if curr.length == nums.length
        res.push(curr.clone)
    else
        for i in 0...nums.length
            if !curr.include?(nums[i])
                curr.push(nums[i])
                generate_permutations(nums, res, curr)
                curr.pop
            end
        end
    end
end

