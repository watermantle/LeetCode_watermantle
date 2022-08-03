class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        def countLessEqual(matrix, mid, smaller, larger):
            count, n = 0, len(matrix)
            row, col = n - 1, 0

            while row >= 0 and col < n:
                if matrix[row][col] > mid:
                    # if the number is greater than mid, keep the track of
                    # the smallest number greater than mid
                    larger = min(larger, matrix[row][col])
                    row -= 1
                else:
                    smaller = max(smaller, matrix[row][col])
                    col += 1
                    count += row + 1
                    
            return count, smaller, larger
            
        n = len(matrix)
        start, end = matrix[0][0], matrix[n - 1][n - 1]
        while start < end:
            mid = (end - start) / 2 + start
            smaller, larger = matrix[0][0], matrix[n - 1][n - 1]
            
            count, smaller, larger = countLessEqual(matrix, mid, smaller, larger)
            
            if count == k: return smaller
            if count < k: 
                start = larger
            else:
                end = smaller
        return start