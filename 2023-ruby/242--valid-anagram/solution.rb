# @param {String} s
# @param {String} t
# @return {Boolean}

# Category: Arrays & Hashing
# Runtime: O(2n)
def is_anagram(s, t)
    return false if s.length != t.length

    letters = Hash.new
    for letter in s.chars
        if letters.key?(letter)
            letters[letter] += 1
        else
            letters[letter] = 1
        end
    end
    for letter in t.chars
        if letters.key?(letter)
            letters[letter] -= 1
            letters.delete(letter) if letters[letter] < 1
        else
            return false
        end
    end
    return true
end

