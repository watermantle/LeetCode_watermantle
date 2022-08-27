class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        # max prefix sum for 1D array
        def maxSumSubarray(arr):
            sub_s_max = -float('inf')
            s_curr = 0
            prefix_sums = [float('inf')]
            for num in arr:
                # store prefix_sum with a sorted container
                bisect.insort(prefix_sums, s_curr)
                s_curr += num
                i = bisect.bisect_left(prefix_sums, s_curr - k)
                sub_s_max = max(sub_s_max, s_curr - prefix_sums[i])
            return sub_s_max
        
        m, n = len(matrix), len(matrix[0])
        for row in range(m):
            for col in range(n - 1):
                matrix[row][col + 1] += matrix[row][col]
        
        res = -float('inf')
        for i1 in range(n):
            for i2 in range(i1, n):
                arr = [matrix[j][i2] - (matrix[j][i1 - 1] if i1 > 0 else 0) for j in range(m)]
                res = max(res, maxSumSubarray(arr))
        return res