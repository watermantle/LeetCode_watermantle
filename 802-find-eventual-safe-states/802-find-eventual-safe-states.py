class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        res = []
        color = [0] * len(graph)
        
        def dfs(node):
            color[node] = 1
            
            for curr in graph[node]:
                if (color[curr] == 0 and dfs(curr)) or color[curr] == 1:
                    return True
            color[node] = 2
            return False
        
        for i in range(len(graph)):
            if color[i] == 2 or not dfs(i):
                res.append(i)
        return res