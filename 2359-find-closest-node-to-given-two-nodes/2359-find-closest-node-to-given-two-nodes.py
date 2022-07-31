class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def dfs(i, dis, edges, memo):
            while i != -1 and memo[i] == -1:
                memo[i] = dis
                dis += 1
                i = edges[i]
                
        memo1 = [-1] * len(edges)
        memo2 = [-1] * len(edges)
        dfs(node1, 0, edges, memo1)
        dfs(node2, 0, edges, memo2)
        
        res = -1
        dis_min = float("inf")
        
        for i in range(len(edges)):
            if (min(memo1[i], memo2[i]) >= 0 and max(memo1[i], memo2[i]) < dis_min):
                dis_min = max(memo1[i], memo2[i])
                res = i
        return res