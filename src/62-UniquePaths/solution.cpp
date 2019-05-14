class Solution {
public:
    // O(m * n) - Only calculate each tile once.
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // There's one way to get to the start.
                    dp[0][0] = 1;
                } else {
                    dp[i][j] = 0;
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                } 
            }
        }
        return dp[m - 1][n - 1];
    }
};