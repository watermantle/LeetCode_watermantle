class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> stk = {INT_MAX};
        
        for (int& num: arr) {
            while (stk.back() < num) {
                int mid = stk.back(); stk.pop_back();
                res += mid * min(stk.back(), num);
            }
            stk.push_back(num);
        }
        for (int i = 2; i < stk.size(); ++i) {
            res += stk[i] * stk[i - 1];
        }
        return res;
    }
};