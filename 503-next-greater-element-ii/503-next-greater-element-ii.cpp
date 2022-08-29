class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        stack<int> stk;
        
        for (int i = 2 * nums.size() - 1; i >= 0; --i) {
            // maintain a monotonic stack, pop item until the top item is the largest one
            while (!stk.empty() && nums[stk.top()] <= nums[i % nums.size()]) stk.pop();
            
            res[i % nums.size()] = stk.empty() ? -1 : nums[stk.top()];
            stk.push(i % nums.size());
        }
        return res;
    }
};