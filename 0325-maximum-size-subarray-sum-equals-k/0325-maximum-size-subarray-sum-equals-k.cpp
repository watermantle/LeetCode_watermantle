class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        long prefix_sum = 0;
        unordered_map<long, int> idxs;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            
            if (prefix_sum == k) res = i + 1;
            if (idxs.count(prefix_sum - k) != 0) {
                res = max(res, i - idxs[prefix_sum - k]);
            }
            
            if (idxs.count(prefix_sum) == 0) idxs[prefix_sum] = i;
        }
        return res;
    }
};