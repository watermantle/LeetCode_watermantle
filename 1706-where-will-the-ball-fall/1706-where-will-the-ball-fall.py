class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        def dfs(r, c):
            if r == m: return c
            c_new = c + grid[r][c]
            if c_new < 0 or c_new > n - 1 or grid[r][c] != grid[r][c_new]:
                return -1
            return dfs(r + 1, c_new)
        
        res = []
        for i in range(n):
            res.append(dfs(0, i))
        return res