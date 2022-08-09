class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int curr_max = *max_element(nums.begin(), nums.end());
        vector<int> houses(curr_max + 1, 0);
        for (int& num: nums) houses[num]++;
        
        vector<int> dp(curr_max + 1, 0);
        dp[0] = houses[0];
        dp[1] = houses[1];
        for (int i = 2; i < curr_max + 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + houses[i] * i);
        }
        return dp[curr_max];
    }
};