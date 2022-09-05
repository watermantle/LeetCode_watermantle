class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n = len(costs)
        k = len(costs[0])
        
        @lru_cache(maxsize=None)
        def paint_cost(hn, color):
            curr = costs[hn][color]
            if hn == n - 1: return curr
            cost = float('inf')
            for next_color in range(k):
                if next_color == color: continue
                
                cost = min(cost, paint_cost(hn + 1, next_color))
            return cost + curr
        
        res = float('inf')
        for color in range(k):
            res = min(res, paint_cost(0, color))
        return res