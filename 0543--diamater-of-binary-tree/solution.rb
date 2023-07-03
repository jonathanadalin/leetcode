# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @return {Integer}

# Category: Trees
# Runtime: O(n)
# Idea: Calculate the depth of each node and while traversing the tree,
# maintain a global maximum diameter variable.
def diameter_of_binary_tree(root)
    $max = 0
    depth(root)
    return $max
end

def depth(node)
    return 0 unless node
    
    left = depth(node.left)
    right = depth(node.right)
    $max = [$max, left + right].max
    return 1 + [left, right].max
end

