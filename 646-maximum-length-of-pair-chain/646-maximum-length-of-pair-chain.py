class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[0])
        
        def chainable(p1, p2):
            if p1[1] < p2[0]: return True
            return False
        
        n = len(pairs)
        dp = [1] * n
        
        for i in range(1, n):
            for j in range(i):
                if chainable(pairs[j], pairs[i]):
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
        