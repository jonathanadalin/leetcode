class Solution {
public:
    // O(n^2)
    int numTrees(int n) {
        if (n == 0) {
            return n;
        }
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int level = 2; level <= n; level++) {
            dp[level] = 0;
            for (int root = 1; root <= level; root++) {
                dp[level] += (dp[root - 1]          // Left of root
                              * dp[level - root]);  // Right of root
            }
        }
        return dp[n];
    }
};