class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        // n x 2 mat, dp[i][0] stores longth of increasing subsequence
        // dp[i][1] stores number of longest
        vector<vector<int>> dp(n, vector<int> (2, 1));
        int len = 1;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            int curr_longest = 1;
            int count = 0;
            
            for (int j = 0; j < i; ++j) {
                if (nums[j] < num) {
                    // as right bound is greater than nums[0 : j]
                    curr_longest = max(curr_longest, dp[j][0] + 1);
                }
            }
            for (int j = 0; j < i; ++j) {
                if (nums[j] < num && dp[j][0] == curr_longest - 1) {
                    count += dp[j][1];
                }
            }
            dp[i][0] = curr_longest;
            dp[i][1] = max(dp[i][1], count);
            len = max(len, curr_longest);
        }
        int res = 0;
        
        for (auto& item: dp) {
            if (item[0] == len) {
                res += item[1];
            }
        }
        return res;
    }
};