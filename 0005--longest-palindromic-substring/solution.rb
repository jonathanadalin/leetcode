# Runtime: O(n^2)
# Notes: Expand around a moving center, but we should consider that palindromes
# can be odd or even length
def longest_palindrome(s)
    return s if s.length < 2

    max = 0
    start = 0
    for i in 0...s.length # O(n^2)
        odd_length = expand_palindrome(s, i, i) # O(n)
        even_length = expand_palindrome(s, i, i + 1) # O(n)
        local_max = [odd_length, even_length].max
        if local_max > max
            max = local_max
            start = i - (max - 1) / 2
        end
    end
    return s[start, max]
end

def expand_palindrome(s, left, right)
    # O(n)
    while left >= 0 && right < s.length && s[left] == s[right]
        left -= 1
        right += 1
    end
    return right - left - 1  # length of substring bound by left and right, minus 2.
end

=begin

Calculations for "start"

Case 1

babad
01234

i = 1
max = 3
start = 0

Case 2

cbbd
0123

i = 1
max = 2
start = 1

=end

