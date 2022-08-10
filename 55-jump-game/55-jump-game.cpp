class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int res = nums.size() - 1;
        for (int i = n; i >= 0; --i) {
            if (i + nums[i] >= res) res = i;
        }
        return res == 0;
    }
};