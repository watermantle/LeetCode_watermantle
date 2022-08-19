class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 2) return true;
        
        bool res1 = true, res2 = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] <= nums[i]) continue;
            else {
                res1 = false;
                break;
            }
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] >= nums[i]) continue;
            else {
                res2 = false;
                break;
            }
        }
        return res1 || res2;
    }
};