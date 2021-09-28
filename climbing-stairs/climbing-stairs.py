class Solution:
    def climbStairs(self, n: int) -> int:
        one, two, curr = 1, 1, 1
        for i in range(2, n+1):
            curr = one + two
            two = one
            one = curr
        
        return curr