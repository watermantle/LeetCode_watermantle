class Solution:
    def numSquares(self, n: int) -> int:
        sq_nums = [i ** 2 for i in range(int(n ** 0.5 + 1))]
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        
        for i in range(1, n + 1):
            for sq_num in sq_nums:
                if i >= sq_num:
                    dp[i] = min(dp[i], dp[i - sq_num] + 1)
        return dp[-1]