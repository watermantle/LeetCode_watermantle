class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        vector<int> nums1, nums2;
        
        for (int i = 1; i < n; ++i) nums1.push_back(nums[i]);
        for (int i = 0; i < n - 1; ++i) nums2.push_back(nums[i]);
        
        int h1, h2;
        h1 = houseRobber(nums1);
        h2 = houseRobber(nums2);
        return max(h1, h2);
    }
private:
    int houseRobber(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};