from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        queue = deque([])
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j))
        
        if len(queue) == m * n: return -1
        
        dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        
        while queue:
            res += 1
            size = len(queue)
            while size:
                r, c = queue.popleft()
                for i in range(4):
                    nr = r + dirs[i][0]
                    nc = c + dirs[i][1]
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 0:
                        queue.append((nr, nc))
                        grid[nr][nc] = 1
                size -= 1
        return res - 1