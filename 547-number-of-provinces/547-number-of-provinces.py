class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        seen = set()
        def dfs(i):
            row = isConnected[i]
            for j, status in enumerate(row):
                if j not in seen and status == 1:
                    seen.add(j)
                    dfs(j)
        res = 0
        
        for i in range(len(isConnected)):
            if i not in seen:
                dfs(i)
                res += 1
        return res