"""
Idea: Use a hashmap to track the old to new mapping.
      Traverse the old graph with DFS returning if there is already
      a key for that node in the hashmap. If not, add a new node
      and its neighbors. When adding neighbors, recursively call the
      DFS function so the newly created node is added.
Time: O(V + E) where V and E are the number of vertices and edges.
Space: O(V + E)
"""

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        old_to_new = {}
        def dfs(node):
            if node in old_to_new:
                return old_to_new[node]
            
            curr = Node(node.val)
            old_to_new[node] = curr
            for nei in node.neighbors:
                curr.neighbors.append(dfs(nei))
            return curr
        
        return dfs(node)
    
