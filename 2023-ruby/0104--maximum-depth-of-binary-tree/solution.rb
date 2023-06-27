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
def max_depth(root)
    return 0 unless root

    depth = 1
    depth += [max_depth(root.left), max_depth(root.right)].max
    return depth
end

