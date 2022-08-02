class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        res = matrix[0]
        i = 1
        m, n = len(matrix), len(matrix[0])
        while len(res) < m * n:
            temp = matrix[i]
            if temp[0] >= res[-1]:
                res.extend(temp)
            else:
                mg_sort = []
                i1, i2 = 0, 0
                while i1 < len(res) and i2 < len(temp):
                    if res[i1] <= temp[i2]:
                        mg_sort.append(res[i1])
                        i1 += 1
                    else:
                        mg_sort.append(temp[i2])
                        i2 += 1
                while i1 < len(res):
                    mg_sort.append(res[i1])
                    i1 += 1
                while i2 < len(temp):
                    mg_sort.append(temp[i2])
                    i2 += 1
                res = mg_sort
            i += 1
        print(res)
        return res[k - 1]