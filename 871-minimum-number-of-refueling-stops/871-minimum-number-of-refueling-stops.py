class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        # dp[i][j] means the max dis we can reach with j stops in ith stations
        n = len(stations)
        
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = startFuel
            
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                # don't stop at the curr station, the dis 
                dp[i][j] = dp[i - 1][j]
                # we can reach the station
                if (dp[i - 1][j - 1] >= stations[i - 1][0]):
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1])
        
        for i, d in enumerate(dp[n]):
            if d >= target:
                return i
        return -1
        