class Solution:
    def arrangeCoins(self, n: int) -> int:
        def prefix(n):
            return (1 + n) * n / 2
        
        left, right = 1, n
        
        while left <= right:
            mid = left + (right - left) // 2
            if n > prefix(mid): left = mid + 1
            elif prefix(mid) == n: return mid
            else: right = mid - 1
        return right