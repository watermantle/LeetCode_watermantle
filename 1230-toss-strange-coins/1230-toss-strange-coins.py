class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        if target > len(prob): return 0
        
        dp = [[0] * (target + 1) for _ in range(len(prob) + 1)]
        
        dp[0][0] = 1
        for i in range(1, len(prob) + 1):
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1])
        
        for i in range(1, len(prob) + 1):
            for t in range(1, min(target, i) + 1):
                dp[i][t] = dp[i - 1][t] * (1 - prob[i - 1]) + dp[i - 1][t - 1] * prob[i - 1]
        return dp[-1][-1]