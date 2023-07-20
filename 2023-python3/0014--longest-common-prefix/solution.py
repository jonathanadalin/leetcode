"""
Category: Arrays
Idea:     The first entry of strs is the prefix. Loop through
          the other strings and if they don't match at a set
          index (here, i), then return the substring up to i.
Time:     O(N * M) where 
            N is the length of strs, 
            M is the length of a string in strs
Space:    O(1) - No additional space is allocated.
"""
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        for i in range(len(strs[0])):
            j = 1
            while j < len(strs):
                if i >= len(strs[j]):
                    return strs[0][:i]
                if strs[0][i] != strs[j][i]:
                    return strs[0][:i]
                j += 1
        return strs[0]

