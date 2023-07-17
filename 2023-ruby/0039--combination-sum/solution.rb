# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}

# Category: Backtracking
# Runtime:  O(size of candidates ^ target)
def combination_sum(candidates, target)
    sorted = candidates.sort_by { |a| -1 * a }
    res = []
    curr = []
    i = 0
    build_res(sorted, target, res, curr, i)
    return res
end

def build_res(candidates, target, res, curr, i)
    if target == 0
        res.push(curr.clone)
        curr.pop
        return
    end
    if i >= candidates.length
        curr.pop
        return
    end
    if candidates[i] <= target
        curr.push(candidates[i])
        # Take the candidate
        build_res(candidates, target - candidates[i], res, curr, i)
    end
    # Try other ones too
    build_res(candidates, target, res, curr, i + 1)
end

