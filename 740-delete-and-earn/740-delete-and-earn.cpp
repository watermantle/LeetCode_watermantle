class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int curr_max = INT_MIN, curr_min = INT_MAX;
        unordered_map<int, int> mp;
        for (int& num: nums) {
            mp[num]++;
            curr_max = max(curr_max, num);
            curr_min = min(curr_min, num);
        }
        
        vector<int> houses;
        for (int i = curr_min; i <= curr_max; ++i) {
            houses.push_back(mp[i] * i);
        }
        int res = houseRobber(houses);
        return res;
    }
private:
    int houseRobber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};