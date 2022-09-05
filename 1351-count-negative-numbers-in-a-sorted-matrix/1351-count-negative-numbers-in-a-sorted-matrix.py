class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        def bi_s(row):
            left = 0 
            right = len(row) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if row[mid] < 0:
                    right = mid - 1
                else:
                    left = mid + 1
            return len(row) - right - 1
        res = 0
        for row in grid:
            res += bi_s(row)
        return res