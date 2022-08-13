class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += mat[i][i];
            sum += mat[i][m - i - 1];
        }
        if (m % 2 == 1) sum -= mat[m / 2][m / 2];
        return sum;
    }
};