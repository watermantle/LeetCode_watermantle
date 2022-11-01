class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        for (int i = 0; i < grid[0].size(); ++i) {
            res.push_back(findBallCol(grid, 0, i));
        }
        return res;
    }
private:
    int findBallCol(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r == m) return c;
        int c_new = c + grid[r][c];
        if (c_new < 0 or c_new >= n or grid[r][c] != grid[r][c_new]) {
            return -1;
        }
        return findBallCol(grid, r + 1, c_new);
    }
};