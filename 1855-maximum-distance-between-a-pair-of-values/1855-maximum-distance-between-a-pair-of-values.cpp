class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int mid;
        
        for (int i = 0; i < nums1.size(); ++i) {
            int left = i, right = nums2.size() - 1;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (nums2[mid] < nums1[i]) right = mid - 1;
                else left = mid + 1;
            }
            res = max(res, right - i);
        }
        return res;
    }
};