class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] < p2[0];
        });
        
        int res = 0;
        int n = pairs.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        for (int& i: dp) {
            res = max(res, i);
        }
        return res;
    }
};