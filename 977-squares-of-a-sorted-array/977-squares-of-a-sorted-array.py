class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        n = len(A)
        res = [0] * n
        left, right = 0, n - 1
        
        for i in range(n - 1, -1, -1):
            if abs(A[right]) > abs(A[left]):
                sq = A[right]
                right -= 1
            else:
                sq = A[left]
                left += 1
            res[i] = sq * sq
        return res
        