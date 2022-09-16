class Solution {
public:
    typedef unsigned long long ull;
    int numSquares(int n) {
        vector<ull> sq_nums;
        for (int i = 0; i < sqrt(n) + 1; ++i) sq_nums.push_back(i * i);
        vector<ull> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (ull& num: sq_nums) {
            for (int i = num; i <= n; ++i) {
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[n];
    }
};