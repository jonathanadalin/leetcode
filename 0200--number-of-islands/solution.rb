# @param {Character[][]} grid
# @return {Integer}
def num_islands(grid)
    count = 0
    m = grid.length
    n = grid[0].length
    for i in 0...m
        for j in 0...n
            if grid[i][j] == '1'
                count += 1
                tag_island(grid, i, j, m, n)
            end
        end
    end
    return count
end

def tag_island(grid, i, j, m, n)
    return if i < 0 || i >= m
    return if j < 0 || j >= n
    return if grid[i][j] == '0'

    grid[i][j] = '0'
    tag_island(grid, i - 1, j, m, n) # up
    tag_island(grid, i + 1, j, m, n) # down
    tag_island(grid, i, j - 1, m, n) # left
    tag_island(grid, i, j + 1, m, n) # right
end

