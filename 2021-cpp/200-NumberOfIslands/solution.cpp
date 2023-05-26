class Solution {
public:
    // O(n), where n is the size of the grid
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int island_count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    island_count++;
                    tagLand(i, j, grid);
                }
            }
        }
        return island_count;
    }
    void tagLand(int x, int y, vector<vector<char>>& grid) {
        int x_size = grid.size();
        int y_size = grid[0].size();
        if (x >= 0 && x < x_size && y >= 0 && y < y_size) {
            if (grid[x][y] == '1') {
                grid[x][y] = '0';
                tagLand(x - 1, y, grid);  // Left
                tagLand(x + 1, y, grid);  // Right
                tagLand(x, y - 1, grid);  // Up
                tagLand(x, y + 1, grid);  // Down
            }

        }
    }
    
    // Helper function
    void displayLand(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                std::cout << " " << grid[i][j];
            }
            std::cout << std::endl;
        }
    }
};