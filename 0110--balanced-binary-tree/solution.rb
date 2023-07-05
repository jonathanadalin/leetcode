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
# @return {Boolean}
# Category: Trees
# Runtime: O(N^2)
# Notes: We can probably improve if we didn't recalculate height every time
def is_balanced(root)
    return true if root == nil
    return false if (height(root.left) - height(root.right)).abs > 1
    return false if is_balanced(root.left) == false || is_balanced(root.right) == false
    return true
end

def height(node)
    return 0 if node == nil
    return 1 + [height(node.left), height(node.right)].max
end

