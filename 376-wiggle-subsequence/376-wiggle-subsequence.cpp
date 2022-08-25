class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int n = nums.size();
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                }
                else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        return max(up[n - 1], down[n - 1]) + 1;
    }
};