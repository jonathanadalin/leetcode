# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Category: Trees
Idea:     Traverse the tree and if either p or q match the current node, then the LCA is the node.
          If p or q are on opposite branches of the current node, the LCA is the node.
          Else, they are on the same subbranch, and we should traverse that subbranch.
Runtime:  O(log N) - we only traverse at most the height of the tree.
"""
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.traverse(root, p ,q)

    def traverse(self, node, p, q):
        if p.val == node.val or q.val == node.val:
            return node
        elif p.val < node.val and q.val > node.val:
            return node
        elif p.val > node.val and q.val < node.val:
            return node
        elif p.val > node.val and q.val > node.val:
            return self.traverse(node.right, p, q)
        else:
            return self.traverse(node.left, p, q)

