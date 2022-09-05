class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        for (int i = 0, found = 0; !found && i < grid.size(); ++i) {
            for (int j = 0; !found && j < grid.size(); ++j) {
                found = paint(grid, i, j);
            }
        }
        
        for (int color = 2; ; ++color) {
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid.size(); ++j) {
                    if (grid[i][j] == color && ((expand(grid, i - 1, j, color) || expand(grid, i + 1, j, color) || expand(grid, i, j + 1, color) || expand(grid, i, j - 1, color)))) return color - 2;
                }
            }
        }
    }
private:
    // paint function to paint one of the islands to 2
    int paint(vector<vector<int>>& G, int r, int c) {
        int n = G.size();
        if (min(r, c) < 0 || max(r, c) == n || G[r][c] != 1) return 0;
        G[r][c] = 2;
        return 1 + paint(G, r + 1, c) + paint(G, r - 1, c) + paint(G, r, c + 1) + paint(G, r, c - 1);
    }
    // expand the painted island with color + 1 to store the length
    bool expand(vector<vector<int>>& G, int r, int c, int color) {
        int n = G.size();
        if (min(r, c) < 0 || max(r, c) == n) return false;
        G[r][c] = G[r][c] == 0 ? color + 1 : G[r][c];
        return G[r][c] == 1;
    }
};