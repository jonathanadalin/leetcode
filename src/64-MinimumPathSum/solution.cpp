class Solution {
public:
    // O(size of grid) - We only performa calculation
    // on each tile once.
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int dp[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    if (i == 0) {
                        // Can only come from top.
                        dp[i][j] = grid[i][j] + dp[i][j - 1];
                    } else if (j == 0) {
                        // Can only come from the left.
                        dp[i][j] = grid[i][j] + dp[i - 1][j];
                    } else {
                        // Can come from above and left.
                        dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
                
            }
        }
        return dp[rows - 1][cols - 1];
    }
};