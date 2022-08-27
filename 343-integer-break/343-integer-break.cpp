class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // we need to consider dp[i - j] * dp[j] as well, but obvisouly, it always gives the min outcome
                // for example, if i = 4, j = 2, dp[i-j] = dp[2] = 1, dp[i - j] * j = 1 * 2 = 2
                // (i-j) * j= (4-2) * 2 = 4
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};