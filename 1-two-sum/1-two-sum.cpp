class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (mp.count(diff)) return {i, mp[diff]};
            else mp[nums[i]] = i;
        }
        return {};
    }
};