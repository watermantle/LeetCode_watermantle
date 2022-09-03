class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        if n == 1: return [i for i in range(10)]
        
        res = []
        
        # dfs solution to consider the problem as a tree
        def dfs(n, num):
            if n == 0:
                res.append(num)
                return res
            
            tail = num % 10
            next_digit = set([tail + k, tail - k])
            
            for digit in next_digit:
                if digit >= 0 and digit < 10:
                    new_num = num * 10 + digit
                    dfs(n - 1, new_num)
        
        for num in range(1, 10):
            dfs(n - 1, num)
        return res