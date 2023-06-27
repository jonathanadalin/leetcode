# Category: Tries

class TrieNode
    def initialize()
        @children = Array.new(26)
        @end = false
    end

    def child(char)
        return @children[to_index(char)]
    end

    def new_child(char)
        @children[to_index(char)] = TrieNode.new()
    end

    def to_index(char)
        char.ord - 'a'.ord
    end

    def set_end(bool)
        @end = bool
    end

    def is_end?
        return @end
    end
end

class Trie
    def initialize()
        @root = TrieNode.new
        @end = false
    end

=begin
    :type word: String
    :rtype: Void
=end
    # Runtime: O(length of word)
    def insert(word)
        curr = @root
        for char in word.chars
            if curr.child(char) == nil
                curr.new_child(char)
            end
            curr = curr.child(char)
        end
        curr.set_end(true)
    end

=begin
    :type word: String
    :rtype: Boolean
=end
    # Runtime: O(length of word)
    def search(word)
        curr = @root
        for char in word.chars
            return false unless curr.child(char)

            curr = curr.child(char)
        end
        return curr.is_end?
    end


=begin
    :type prefix: String
    :rtype: Boolean
=end
    # Runtime: O(length of prefix)
    def starts_with(prefix)
        curr = @root
        for char in prefix.chars
            return false unless curr.child(char)

            curr = curr.child(char)
        end
        return true
    end

end

# Your Trie object will be instantiated and called as such:
# obj = Trie.new()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.starts_with(prefix)
