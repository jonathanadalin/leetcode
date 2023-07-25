"""
Idea: Traverse the matrix. When we come across an island of value
      1, set that value to 0 so we know we visited it, and increase
      a count variable. Check neighboring islands to see if they are 
      1s and apply the same logic recusively.
Time: O(m * n)
Space: O(1)
"""

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return 0 
        n = len(grid[0])
        if n == 0:
            return 0

        largest_size = 0
        for i in range(m):
            for j in range(n):
                def expand(x, y):
                    if not 0 <= x < m:
                        return 0
                    if not 0 <= y < n:
                        return 0
                    if grid[x][y] == 0:
                        return 0

                    grid[x][y] = 0 # mark the island visited
                    size = 1
                    size += expand(x + 1, y) # right
                    size += expand(x - 1, y) # left
                    size += expand(x, y + 1) # down
                    size += expand(x, y - 1) # up
                    return size
                
                size = expand(i, j)
                largest_size = max(largest_size, size)

        return largest_size

