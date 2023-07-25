"""
Idea: Build the adjacency graph traversing the graph with a set
      to keep track of visited nodes.
      Build a new graph using the adjacency graph.
Time: O(n^2) - Number of nodes * number of neighbors
Space: O(n^2)
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

        # Build the adjacency graph
        stack = []
        adj_map = {}
        traversed = set()
        def traverse(node: 'Node') -> 'Node':
            if not node:
                return 
            if node.val not in adj_map:
                adj_map[node.val] = set()
            for neighbor in node.neighbors:
                adj_map[node.val].add(neighbor.val)
                if neighbor.val not in traversed:
                    stack.append(neighbor)
            traversed.add(node.val)
            if len(stack) > 0:
                traverse(stack.pop())
        traverse(node)
        
        # Build the new graph from the adjacency graph
        if len(adj_map) == 0:
            return None
        new_nodes = {}
        first = 0
        for k in adj_map.keys():
            if len(new_nodes) == 0:
                first = k
            new_nodes[k] = Node(k)

        for k, v in adj_map.items():
            new_nodes[k].neighbors = []
            for neighbor in v:
                new_nodes[k].neighbors.append(new_nodes[neighbor])

        return new_nodes[first]

