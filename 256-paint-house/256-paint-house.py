from functools import lru_cache
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        @lru_cache(maxsize=None)
        
        def paint_cost(n, color):
            total_cost = costs[n][color]
            if n == len(costs) - 1: return total_cost
            elif color == 0:
                total_cost += min(paint_cost(n + 1, 1), paint_cost(n + 1, 2))
            elif color == 1:
                total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 2))
            elif color == 2:
                total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 1))
            return total_cost
        
        if not costs: return 0
        return min(paint_cost(0, 0), paint_cost(0, 1), paint_cost(0, 2))