class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 1 or n == 2: return 1
        if n == 3: return 2
        
        @lru_cache(None)
        def helper(n):
            res = n
            
            for i in range(1, n // 2 + 1):
                res = max(helper(i) * helper(n-i), res)
            return res
        return helper(n)