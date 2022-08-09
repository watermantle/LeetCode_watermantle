class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        res = 0
        arr.sort()
        n = len(arr)
        dp = [1] * n
        mod = 10 ** 9 + 7
        index = {num: i for i, num in enumerate(arr)}
        
        for i in range(n):
            for j in range(i):
                if arr[i] % arr[j] == 0:
                    right = arr[i] // arr[j]
                    if right in index:
                        dp[i] += dp[j] * dp[index[right]]
                        dp[i] %= mod
        return sum(dp) % mod
                    