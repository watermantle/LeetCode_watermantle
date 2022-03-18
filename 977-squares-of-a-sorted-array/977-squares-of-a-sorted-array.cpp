class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        
        for (int i = n - 1; i >= 0; --i){
            int sq;
            if (abs(nums[left]) < abs(nums[right])) sq = nums[right--];
            else sq = nums[left++];
            
            res[i] = sq * sq;
        }
    return res;
    }
};