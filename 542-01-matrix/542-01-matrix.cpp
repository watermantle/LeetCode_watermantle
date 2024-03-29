class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if (m == 0) return mat;
        vector<vector<int>> res(m, vector<int> (n, INT_MAX - 100000));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) res[i][j] = 0;
                else {
                    if (i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                    if (j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < m - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if (j < n - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }
        return res;
    }
};