class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (int m = 0; m < accounts.size(); ++m) {
            int sum = 0;
            for (int n = 0; n < accounts[0].size(); ++n) {
                sum += accounts[m][n];
            }
            res = max(sum, res);
        }
        return res;
    }
};