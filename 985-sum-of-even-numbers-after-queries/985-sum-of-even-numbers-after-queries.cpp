class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int curr = 0;
        for (int& num: nums) {
            if (num % 2 == 0) curr += num;
        }
        
        for (auto& query: queries) {
            int idx = query[1];
            // two odd numbers add togather
            if (abs(nums[idx]) % 2 == 1 && abs(query[0]) % 2 == 1) {
                curr += nums[idx] + query[0];
            }
            // two even numbers
            else if (nums[idx] % 2 == 0 && query[0] % 2 == 0) {
                curr += query[0];
            }
            // prveously even after add new, need to be removed
            else if (nums[idx] % 2 == 0 && abs(query[0]) % 2 == 1) {
                curr -= nums[idx];
            }
            // update nums
            nums[idx] += query[0];
            res.push_back(curr);
        }
        return res;
    }
};