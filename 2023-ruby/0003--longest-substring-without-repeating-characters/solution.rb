# @param {String} s
# @return {Integer}

# Category: Sliding Window
# Runtime: O(n) - single pass of s with O(1) operations
def length_of_longest_substring(s)
    return 0 if s.length == 0
    return 1 if s.length == 1

    chars = s.chars
    max = 0
    left = 0
    right = 0
    set = Set.new
    while right < s.length
        if set.include?(chars[right])  # O(1) - Set search
            while chars[left] != chars[right]
                set.delete(chars[left])  # O(1) - Set deletion
                left += 1
            end
            left += 1
        else
            set.add(chars[right])  # O(1) - Set insertion
            max = [max, set.length].max
        end
        right += 1
    end
    return max
end

