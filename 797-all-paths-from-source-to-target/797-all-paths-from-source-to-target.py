from collections import deque
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        queue = deque([(0, [0])])
        res = []
        target = len(graph) - 1
        
        while queue:
            node, path = queue.popleft()
            if node == target:
                res.append(path)
            else:
                for n in graph[node]:
                    queue.append((n, path + [n]))
        return res