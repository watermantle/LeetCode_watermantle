class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums2.size(); ++i) idx[nums2[i]] = i;
        vector<int> res;
        
        for (int& num: nums1) {
            int id = idx[num];
            while (id < nums2.size()) {
                if (nums2[id] > num) {
                    res.push_back(nums2[id]);
                    break;
                }
                id++;
            }
            if (id == nums2.size()) res.push_back(-1);
        }
        return res;
    }
};