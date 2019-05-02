class Solution {
public:
    vector<int> countBits(int num) {
        int dp[num + 1];
        dp[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1) {
                dp[i] = 1 + dp[i/2];
            } else {
                dp[i] = dp[i/2];
            }
        }
        vector<int> v;
        for (int i = 0; i <= num; i++) {
            v.push_back(dp[i]);
        }
        return v;
    }
};