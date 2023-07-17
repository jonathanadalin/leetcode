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
# Runtime: O(N)
def is_balanced(root)
    return true if root == nil
    return false if dfs_height(root) == -1
    return true
end

def dfs_height(node)
    return 0 if node == nil
    left = dfs_height(node.left)
    right = dfs_height(node.right)
    return -1 if left == -1
    return -1 if right == -1
    return -1 if (left - right).abs  > 1
    return [left, right].max + 1
end

