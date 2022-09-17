class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> factors;
        dfs(res, factors, n);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& factors, int n) {
        int i = factors.empty() ? 2 : factors.back();
        
        for (; i <= n / i; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                factors.push_back(n / i);
                res.push_back(factors);
                factors.pop_back();
                dfs(res, factors, n / i);
                factors.pop_back();
            }
        }
    }
};