# Category: Trees
# Runtime: O(Size of root * size of subroot)
#
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
# @param {TreeNode} sub_root
# @return {Boolean}
def is_subtree(root, sub_root)
    return true if root == nil && sub_root == nil
    return true if root != nil && sub_root == nil
    return false if root == nil && sub_root != nil
    
    if root.val == sub_root.val
        return true if is_same(root.left, sub_root.left) && is_same(root.right, sub_root.right)
    end

    return true if is_subtree(root.left, sub_root)
    return true if is_subtree(root.right, sub_root)
    return false
end

def is_same(a, b)
    return true if a == nil && b == nil
    return false if a == nil && b != nil
    return false if a != nil && b == nil
    return false if a.val != b.val

    return is_same(a.left, b.left) && is_same(a.right, b.right)
end
