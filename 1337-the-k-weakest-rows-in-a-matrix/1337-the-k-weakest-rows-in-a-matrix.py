class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat[0])
        def binary_search(row):
            left = 0
            right = n - 1
            while left <= right:
                mid = left + (right - left) // 2
                if row[mid] == 1:
                    left = mid + 1
                else:
                    right = mid - 1
            return left
        
        row_s = []
        for i, row in enumerate(mat):
            row_s.append((binary_search(row), i))
        row_s.sort()
        
        res = []
        for i in range(k):
            res.append(row_s[i][1])
        return res