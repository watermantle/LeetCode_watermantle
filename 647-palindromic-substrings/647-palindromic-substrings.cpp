class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        if (n <= 0) return 0;
    
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // single letter is true
        for (int i = 0; i < n; ++i, ++res) {
            dp[i][i] = true;
        }
        // check double letters
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            res += dp[i][i + 1];
        }
        
        for (int length = 3; length <= n; ++length) {
            for (int i = 0, j = i + length - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                res += dp[i][j];
            }
        }
        return res;
    }
};