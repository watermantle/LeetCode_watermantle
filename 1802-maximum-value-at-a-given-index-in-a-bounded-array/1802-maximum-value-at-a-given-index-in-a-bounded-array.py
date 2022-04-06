class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def check(a):
            b = max(a - index, 0)
            res = (a + b) * (a - b + 1) / 2
            b = max(a - (n - 1 - index), 0)
            res += (a + b) * (a - b + 1) / 2
            return res - a
        
        maxSum -= n
        left, right = 0, maxSum
        while (left <= right):
            mid = left + (right - left) // 2
            if check(mid) <= maxSum:
                left = mid + 1
            else:
                right = mid - 1
        return left