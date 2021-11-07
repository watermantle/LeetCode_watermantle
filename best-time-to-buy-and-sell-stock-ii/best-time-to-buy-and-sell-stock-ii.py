class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0

        prevdiff = prices[1] - prices[0]
        res = prevdiff if prevdiff > 0 else 0

        for i in range(2, len(prices)):
            diff = prices[i] - prices[i - 1]
            if diff > 0 and prevdiff > 0: res += diff

            if (diff > 0 and prevdiff <= 0):
                res += diff
            prevdiff = diff
        return res