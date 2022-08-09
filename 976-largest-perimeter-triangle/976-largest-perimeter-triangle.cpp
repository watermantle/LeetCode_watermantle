class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; --i) {
            int a = nums[i];
            int b = nums[i - 1];
            int c = nums[i - 2];
            if (checkTri(a, b, c)) return a + b + c;
        }
        return 0;
    }
private:
    bool checkTri(int& a, int& b, int& c) {
        if ((a < b + c) && (a - b < c)) return true;
        return false;
    }
};