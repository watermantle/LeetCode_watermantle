class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        row_maxes = [max(row) for row in grid]
        col_maxes = [max(col) for col in zip(*grid)]
        
        return sum(min(row_maxes[r], col_maxes[c]) - value
                  for r, row in enumerate(grid)
                  for c, value in enumerate(row))