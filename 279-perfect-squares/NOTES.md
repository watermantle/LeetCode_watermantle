**States**: dp[i] is the number of perfect sq for number **i**
**Recurrent relation**: dp[i] = min(dp[i], dp[i-sq] for sq from [i ** 2 for i in range(int(n ** 0.5 + 1))]
**Base cases**: dp with size of (n + 1) with all inf numbers. also, dp[0] = 0 as no perfect sq for 0