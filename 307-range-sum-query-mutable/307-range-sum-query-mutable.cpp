class NumArray {
public:
    vector<int> arr;
    vector<int> memo;
    int len;
    
    NumArray(vector<int>& nums) {
        arr = nums;
        len = ceil(nums.size() / sqrt(nums.size()));
        memo = vector<int> (len, 0);
        for (int i = 0; i < nums.size(); ++i) {
            memo[i / len] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int idx = index / len;
        memo[idx] = memo[idx] - arr[index] + val;
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int start = left / len;
        int end = right / len;
        if (start == end) {
            for (int i = left; i <= right; ++i) {
                sum += arr[i];
            }
        }
        else {
            int left_bound = (start + 1) * len;
            int right_bound = end * len;
            
            for (int i = left; i < left_bound; ++i) {
                sum += arr[i];
            }
            for (int i = start + 1; i < end; ++i) {
                sum += memo[i];
            }
            for (int i = right_bound; i <= right; ++i) {
                sum += arr[i];
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */