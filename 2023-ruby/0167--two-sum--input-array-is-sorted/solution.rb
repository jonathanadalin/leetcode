# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}

# Category: Two pointers
# Runtime: O(n^2) - yikes
def two_sum(numbers, target)
    i = 0
    j = 1
    while i < numbers.length - 1
        if j == numbers.length
            i += 1
            j = i + 1
        elsif numbers[i] + numbers[j] == target
            return [i + 1, j + 1]
        elsif numbers[i] == numbers[j]
            i += 1
            j += 1
        elsif numbers[i] + numbers[j] > target
            i += 1
            j = i + 1
        else j < numbers.length - 1
            j += 1
        end
    end
end

