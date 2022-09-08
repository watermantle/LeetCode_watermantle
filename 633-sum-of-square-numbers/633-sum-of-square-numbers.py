class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        
        def binary_search(left, right, n):
            if left > right: return False
            
            mid = left + (right - left) // 2
            if mid * mid == n: return True
            if mid * mid > n: 
                return binary_search(left, mid - 1, n)
            return binary_search(mid + 1, right, n)
            
        s = 0
        while s * s <= c:
            diff = c - s * s
            if binary_search(0, diff, diff): return True
            s += 1
        return False