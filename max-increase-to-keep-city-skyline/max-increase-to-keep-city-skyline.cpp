class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> row_maxes;
        vector<int> col_maxes;

        for (auto row : grid) {
            int row_max = *max_element(row.begin(), row.end());
            row_maxes.push_back(row_max);
        }

        for (int i = 0; i != n; i++) {
            int col_max = 0;
            for (int j = 0; j != m; j++) {
                if (col_max < grid[j][i]) {
                    col_max = grid[j][i];
                }
            }
            col_maxes.push_back(col_max);
        }

        int res = 0;
        for (int r = 0; r != m; r++) {
            for (int l = 0; l != n; l++) {
                res += min(row_maxes[r], col_maxes[l]) - grid[r][l];
            }
        }
        return res;
    }
};