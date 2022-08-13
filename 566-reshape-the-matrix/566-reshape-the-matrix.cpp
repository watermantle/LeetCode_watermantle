class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        queue<int> temp;
        int m = mat.size();
        int n = mat[0].size();
        
        if (m * n != r * c) return mat;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                temp.push(mat[i][j]);
                cout << mat[i][j] << endl;
            }
        }
        
        vector<vector<int>> res (r, vector<int>(c, 0));
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = temp.front(); temp.pop();
            }
        }
        return res;
    }
};