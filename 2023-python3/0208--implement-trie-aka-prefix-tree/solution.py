"""
Idea: Define a TrieNode class that contains a pointer to next letters
      and a boolean representing if that node is the end of the word.
      Inserting consists of populating the graph with TrieNodes and the
      tail TrieNode will have that boolean set to True.
      Word and prefix searching consists of traversing the graph. Word
      searching is more strict and requires check for the end_of_word
      boolean.
Time: O(size of word or prefix)
Space: O(1) for searches, O(size of word) for inserts
"""

class TrieNode:

    def __init__(self):
        self.next_letters = [None] * 26
        self.end_of_word = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if curr.next_letters[ord(c) - ord('a')] == None:
                curr.next_letters[ord(c) - ord('a')] = TrieNode()
            curr = curr.next_letters[ord(c) - ord('a')]
        curr.end_of_word = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if curr.next_letters[ord(c) - ord('a')] == None:
                return False
            curr = curr.next_letters[ord(c) - ord('a')]
        return curr.end_of_word

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if curr.next_letters[ord(c) - ord('a')] == None:
                return False
            curr = curr.next_letters[ord(c) - ord('a')]
        return True

