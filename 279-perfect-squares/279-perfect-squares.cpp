class Solution {
public:
    typedef unsigned long long ull;
    int numSquares(int n) {
        vector<ull> sq_nums;
        for (int i = 0; i < sqrt(n) + 1; ++i) sq_nums.push_back(i * i);
        vector<ull> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (ull& sq_num: sq_nums) {
                if (i >= sq_num) dp[i] = min(dp[i], dp[i - sq_num] + 1);
            }
        }
        return dp[n];
    }
};