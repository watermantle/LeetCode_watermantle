class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        vector<int> col_maxes;

        for (int i = 0; i != n; i++) {
            int col_max = 0;
            for (int j = 0; j != n; j++) {
                if (col_max < grid[j][i]) {
                    col_max = grid[j][i];
                }
            }
            col_maxes.push_back(col_max);
        }
        
        for (int r = 0; r != n; r++) {
            int row_max = *max_element(grid[r].begin(), grid[r].end());
            for (int l = 0; l != n; l++) {
                res += min(row_max, col_maxes[l]) - grid[r][l];
            }
        }
        return res;
    }
};