class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1: return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        
        for row in range(1, m + 1):
            for col in range(1, n + 1):
                if row == 1 and col == 1:
                    dp[row][col] = 1
                else:
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1]
                    if obstacleGrid[row - 1][col - 1] == 1:
                        dp[row][col] = 0
        return dp[m][n]