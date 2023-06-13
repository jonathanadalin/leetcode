# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}

# Idea: Use two pointers so we only need to make a single pass
# Category: Two pointers
# Runtime: O(n)
def two_sum(numbers, target)
    left = 0
    right = numbers.length - 1
    while left < right
        sum = numbers[left] + numbers[right]
        if sum < target
            left += 1
            next
        end
        if sum > target
            right -= 1
            next
        end
        # sum == target
        return [left + 1, right + 1]
    end      
end

