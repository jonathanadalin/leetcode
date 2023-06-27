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
# @return {TreeNode}

# Category: Trees
# Runtime O(n)
def invert_tree(root)
    invert(root)
    return root
end

def invert(node)
    return unless node
    tmp = node.left
    node.left = node.right
    node.right = tmp
    invert(node.left)
    invert(node.right)
end

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
# @return {TreeNode}

# Runtime: O(n)
def invert_tree_with_stack(root)
    stack = []
    stack.push(root) if root
    while !stack.empty?
        node = stack.pop
        left = node.left
        node.left = node.right
        node.right = left

        stack.push(node.left) if node.left
        stack.push(node.right) if node.right
    end
    return root
end

