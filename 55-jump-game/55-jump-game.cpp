class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] >= i) {
                dp[i] = max(dp[i - 1], i + nums[i]);
            }
        }
        return dp[n - 1] >= n - 1;
    }
};