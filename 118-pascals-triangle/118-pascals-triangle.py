class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1: return [[1]]
        if numRows == 2: return [[1], [1, 1]]
        
        res = [[1], [1, 1]]
        n = numRows - 2
        
        while n:
            last = res[-1]
            temp = [1]
            for i in range(1, len(last)):
                temp.append(last[i - 1] + last[i])
            temp.append(1)
            res.append(temp)
            n -= 1
        return res
            