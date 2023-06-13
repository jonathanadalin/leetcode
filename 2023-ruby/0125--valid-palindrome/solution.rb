# @param {String} s
# @return {Boolean}

# Problem Category: 2 pointers
# Runtime: O(n)
def is_palindrome(s)
    characters = s.downcase.gsub(/[^0-9a-z]/i, '').split("")
    i = 0
    j = characters.length - 1
    while i < j do
        return false if characters[i] != characters[j]

        i += 1
        j -= 1
    end
    return true
end

