from itertools import combinations
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        G = collections.defaultdict(list)
        
        for road in roads:
            G[road[1]].append(road[0])
            G[road[0]].append(road[1])
            
        res = 0
        for road in combinations(range(n), 2):
            curr = 0
            for node in road:
                for n in G[node]:
                    curr += 1
            if road[0] in G[road[1]]:
                curr -= 1
            res = max(res, curr)
        return res