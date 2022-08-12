class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max, curr_min, res;
        curr_min = curr_max = res = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            int temp_max = max(num, max(curr_max * num, curr_min * num));
            curr_min = min(num, min(curr_max * num, curr_min * num));
            curr_max = temp_max;
            res = max(res, curr_max);
        }
        return res;
    }
};