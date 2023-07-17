"""
Category: Arrays & Hashing
Idea:     We can determine whether words are anagrams with whether
          their sorted characters form the same word.
          Group anagrams with a map with the sorted word as the key,
          then reconstruct the final answer as an array as requested.
Runtime:  O(N * M log M)
          where
          N: number of strings
          M: size of each string
"""
class Solution(object):

    def groupAnagrams(self, strs):
        res = []
        anagramGroups = {}
        for word in strs:
            sortedWord = ''.join(sorted(word))
            if sortedWord in anagramGroups:
                anagramGroups[sortedWord].append(word)
            else:
                anagramGroups[sortedWord] = [word]
        
        for anagrams in anagramGroups.values():
            res.append(anagrams)

        return res

