class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> heap(begin(nums), end(nums));
        int i = heap.size();
        while (!heap.empty()){
            nums[--i] = heap.top();
            heap.pop();
        }
        return nums;
    }
};