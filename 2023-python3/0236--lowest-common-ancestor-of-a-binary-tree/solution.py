# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Category: Trees
Idea:     If we DFS and hit the node right away, that node is the LCA.
          If there isn't a match, we should DFS on both sides of the current
          node, "middle". If both sides contain either p or q, the LCA is
          "middle". If we hit either p or q on only one side, the LCA would be
          in that subtree so we should repeat the idea starting from the child
          on that side until one of the earlier LCA conditions get met.
Runtime:  O(n) - Single pass of all nodes of the tree at worst
"""

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.dfs(root, p, q)

    def dfs(self, node, p, q):
        if not node:
            return 0

        if node == p or node == q:
            return node
        
        left = self.dfs(node.left, p, q)
        right = self.dfs(node.right, p, q)        
        if left and right:
            return node
        elif left and not right:
            return left
        else:
            return right

