# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    res = []
    generate_permutations(res, [], nums)
    return res
end

def generate_permutations(res, curr, nums)
    if curr.length == nums.length
        res.push(curr.clone)
        return
    end
    for i in 0...nums.length
        if !curr.include?(nums[i])
            curr.push(nums[i]) 
            generate_permutations(res, curr, nums)
            curr.pop
        end
    end
end

