# @param {String} s
# @return {Boolean}

# Category: Stack
# Runtime: O(n)
# Notes: In Ruby, we can use an array to represent the stack.
def is_valid(s)
    return true if s.length == 0
    return false if s.length % 2 == 1
    stack = []
    for char in s.chars
        case char
        when '(', '{', '['
            stack.push(char)
        when ')'
            return false if stack.pop != '(' 
        when '}'
            return false if stack.pop != '{' 
        when ']'
            return false if stack.pop != '['
        end
    end
    return stack.length == 0
end

