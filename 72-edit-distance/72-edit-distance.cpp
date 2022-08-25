class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        if (n * m == 0) return n + m;
        
        short dp[501][501] = {};
        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i < m + 1; ++i) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                // dp[i - 1][j] meaning word1[:i - 1] and word2[j:], so we need to add one more char, dp[i][j - 1] is the same. 
                int down = dp[i - 1][j] + 1;
                int left = dp[i][j - 1] + 1;
                // dp[i - 1][j - 1] is different, as if word1[i] == word2[j], we don't need to do anything, hence dp[i][j] = dp[i - 1][j - 1], but if word1[i] != word2[j], we need to replace one char
                int left_down = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down++;
                
                dp[i][j] = min(min(down, left), left_down);
            }
        }
        return dp[n][m];
    }
};