class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
private:
    int findMin(vector<int>& nums, int l, int r){
        // the case one or two elements
        if (l + 1 >= r) return min(nums[l], nums[r]);
        // if the array is sorted
        if (nums[l] < nums[r]) return nums[l];
        
        int mid = l + (r - l) / 2;
        return min(findMin(nums, l, mid-1), findMin(nums, mid, r));
    }
};
