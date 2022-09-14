class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        
        // factors, only factors could be used
        vector<int> factors;
        for (int i = 1; i < n / 2 + 1; ++i) {
            // dividable
            if (n % i == 0) factors.push_back(i);
        }
        
        for (int& factor: factors) {
            dp[factor]++;
            for (int i = factor + 1; i < n + 1; ++i) {
                if (i % factor == 0) {
                    dp[i] = min(dp[i], dp[i - factor] + 1);
                }
            }
        }
        return dp[n];
    }
};