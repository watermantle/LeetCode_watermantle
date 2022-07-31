class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int& num1: nums1) {
            for (int& num2: nums2) {
                mp[num1 + num2]++;
            }
        }
        
        for (int& num3: nums3) {
            for (int& num4: nums4) {
                if (mp.count(-num3 - num4)) res += mp[-num3 - num4];
            }
        }
        return res;
    }
};