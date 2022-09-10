from collections import deque
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        if len(graph) == 1: return 0
        
        n = len(graph)
        # if all of the nodes have been visited
        ending_mask = (1 << n) - 1
        
        queue = deque([(node, 1 << node) for node in range(n)])
        seen = set(queue)
        
        res = 0
        
        while queue:
            size = len(queue)
            while size:
                node, mask = queue.popleft()
                for neighbor in graph[node]:
                    next_mask = mask | (1 << neighbor)
                    if next_mask == ending_mask:
                        return res + 1
                    if (neighbor, next_mask) not in seen:
                        seen.add((neighbor, next_mask))
                        queue.append((neighbor, next_mask))
                size -= 1
            res += 1
        return res