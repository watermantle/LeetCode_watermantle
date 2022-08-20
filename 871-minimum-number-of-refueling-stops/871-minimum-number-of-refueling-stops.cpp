typedef unsigned long long ull;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        // dp[i][j] use up to ith out of j stations, the farest dis we can reach
        vector<vector<ull>> dp(n + 1, vector<ull>(n + 1, 0));
        
        // stop 0 station, the farest location is the init fuel
        for (int i = 0; i < n + 1; ++i) dp[i][0] = startFuel;
        
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < i + 1; ++j) {
                dp[i][j] = dp[i - 1][j];
                
                if (dp[i - 1][j - 1] >= stations[i - 1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1]);
                }
            }
        }
        for (int i = 0; i < n + 1; ++i) {
            if (dp[n][i] >= target) return i;
        }
        return -1;
    }
};