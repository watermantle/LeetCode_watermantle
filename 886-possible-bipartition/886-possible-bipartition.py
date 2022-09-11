from collections import deque, defaultdict
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        queue = deque([])
        G = defaultdict(list)
        seen = [0] * n
        
        for e in dislikes:
            # keep 0-based
            G[e[1] - 1].append(e[0] - 1)
            G[e[0] - 1].append(e[1] - 1)
            
        for i in range(n):
            if seen[i]: continue
            seen[i] = 1
            queue.append(i)
            while queue:
                size = len(queue)
                while size:
                    size -= 1
                    node = queue.popleft()
                    for v in G[node]:
                        if seen[v] == 0:
                            seen[v] = 2 if seen[node] == 1 else 1
                            queue.append(v)
                        if seen[v] == seen[node]: return False
        return True
                        