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

# Runtime: O(n)
def max_depth_with_array(root)
    return 0 unless root

    nodes = []
    depths = []
    nodes.push(root)
    depths.push(1)
    max = 0
    while !nodes.empty?
        node = nodes.pop
        depth = depths.pop
        max = [max, depth].max
        if node.left
            nodes.push(node.left)
            depths.push(depth + 1)
        end
        if node.right
            nodes.push(node.right)
            depths.push(depth + 1)
        end
    end
    return max
end

