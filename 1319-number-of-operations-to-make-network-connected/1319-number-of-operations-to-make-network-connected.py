class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1: return -1
        
        G = collections.defaultdict(list)
        for i, j in connections:
            G[i].append(j)
            G[j].append(i)
        
        seen = set()
        
        def dfs(i):
            if i in seen: return 0
            seen.add(i)
            for j in G[i]:
                dfs(j)
            return 1
        
        res = 0
        for i in range(n):
            res += dfs(i)
        return res - 1