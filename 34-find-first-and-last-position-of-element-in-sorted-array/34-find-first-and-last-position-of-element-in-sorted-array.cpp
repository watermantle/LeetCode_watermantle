class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftb = get_left_bound(nums, target);
        int rightb = get_right_bound(nums, target);
        
        if (leftb == -10 || rightb == -10) return {-1, -1};
        if (rightb - leftb > 1) return {leftb + 1, rightb - 1};
        return {-1, -1};
    }
private:
    int get_left_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        int left_bound = -10;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            // look for left bound, the algo should not stop
            // even if it finds a target, when nums[mid] == target
            // ignore the finding and update it
            if (nums[mid] >= target){
                right = mid - 1;
                left_bound = right;
            }else {
                left = mid + 1;
            }
        }
        return left_bound;
    }
    
    int get_right_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        int right_bound = -10;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
                right_bound = left;
            }
        }
        return right_bound;
    }
};