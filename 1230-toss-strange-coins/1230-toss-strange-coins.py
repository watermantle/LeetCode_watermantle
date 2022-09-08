class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        if target > len(prob): return 0
        
        dp = [0] * (target + 1)
        dp[0] = 1
        
        for i in range(0, len(prob)):
            for t in range(target, -1, -1):
                dp[t] = (dp[t - 1] if t else 0) * prob[i] + dp[t] * (1 - prob[i])
        return dp[-1]