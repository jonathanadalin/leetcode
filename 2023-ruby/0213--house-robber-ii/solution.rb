# Category: Dynamic Programming
# Runtime: O(2N)

$db = {}

def rob(nums)
    return 0 if nums.length == 0
    return nums[0] if nums.length == 1
    $db = {}
    pass_first = rob_memoize(nums, 0, 1)
    $db = {}
    take_first = rob_memoize(nums, 1, 0)
    return [pass_first, take_first].max
end

def rob_memoize(nums, i, tail)
    return 0 if i >= nums.length - tail
    unless $db.has_key?(i)
        $db[i] = 
            [
                nums[i] + rob_memoize(nums, i + 2, tail), # rob
                rob_memoize(nums, i + 1, tail)            # pass
            ].max
    end
    return $db[i]
end

