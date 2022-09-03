from collections import deque
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        
        def get_nb(r, c):
            nb = []
            if r > 0:
                if maze[r - 1][c] == '.':
                    nb.append((r - 1, c))
            if c > 0:
                if maze[r][c - 1] == '.':
                    nb.append((r, c - 1))
            if r < m - 1:
                if maze[r + 1][c] == '.':
                    nb.append((r + 1, c))
            if c < n - 1:
                if maze[r][c + 1] == '.':
                    nb.append((r, c + 1))
            return nb
        
        r, c = entrance
        queue = deque([(r, c, 0)])
        seen = set((r, c))
        while queue:
            nr, nc, nd = queue.popleft()
            if  (nr, nc) != (r, c):
                if nr == 0 or nr == m - 1 or nc == n - 1 or nc == 0:
                    return nd
            for new_node in get_nb(nr, nc):
                if (new_node[0], new_node[1]) not in seen:
                    queue.append((new_node[0], new_node[1], nd + 1))
                    seen.add((new_node[0], new_node[1]))
        return -1