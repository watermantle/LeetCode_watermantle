class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int slow = 0, curr = 0; curr < nums.size(); ++curr) {
            if (nums[curr] != 0) {
                swap(nums[slow++], nums[curr]);
            }
        }
    }
};