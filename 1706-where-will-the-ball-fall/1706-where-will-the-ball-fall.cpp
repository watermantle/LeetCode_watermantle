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
        int cNew = c + grid[r][c];
        if (cNew < 0 || cNew >= n || grid[r][c] != grid[r][cNew]) {
            return -1;
        }
        return findBallCol(grid, r + 1, cNew);
    }
};