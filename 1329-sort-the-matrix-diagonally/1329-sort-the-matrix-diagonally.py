class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        
        digs  = collections.defaultdict(list)
        
        for row in range(m):
            for col in range(n):
                digs[row - col].append(mat[row][col])
        
        for dig in digs.values():
            heapq.heapify(dig)
        
        # dig is define as row - col the same
        for row in range(m):
            for col in range(n):
                value = heapq.heappop(digs[row - col])
                mat[row][col] = value
        return mat