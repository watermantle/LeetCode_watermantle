class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> left_max(n, 0), right_max(n, 0);
        
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};