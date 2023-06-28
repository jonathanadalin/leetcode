class TrieNode
    def initialize()
        @children = Array.new(26)
        @is_end = false
    end

    def to_children_index(char)
        char.ord - 'a'.ord
    end

    def get_children
        @children
    end

    def child(char)
        @children[to_children_index(char)]
    end

    def new_child(char)
        @children[to_children_index(char)] = TrieNode.new
    end

    def is_end?
        @is_end
    end

    def set_is_end(bool)
        @is_end = bool
    end
end

class WordDictionary
    def initialize()
        @root = TrieNode.new
    end


=begin
    :type word: String
    :rtype: Void
=end
    def add_word(word)
        curr = @root
        for char in word.chars
            curr.new_child(char) unless curr.child(char)
            curr = curr.child(char)
        end
        curr.set_is_end(true)
    end


=begin
    :type word: String
    :rtype: Boolean
=end
    def search(word)
        search_node(word, @root)
    end

    def search_node(word, node)
        curr = node
        for i in 0...word.length
            char = word.chars[i]
            if char == '.'
                for child in curr.get_children
                    return true if child != nil && search_node(word.slice((i + 1)..-1), child)
                end
                return false
            end
            return false unless curr.child(char)
            curr = curr.child(char)
        end
        return curr.is_end?
    end
end

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary.new()
# obj.add_word(word)
# param_2 = obj.search(word)
