import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        heap_list = []
        for i in range(min(k, n)):
            heap_list.append((matrix[i][0], i, 0))
        heapq.heapify(heap_list)
        
        while k:
            ele, r, c = heapq.heappop(heap_list)
            if c < n - 1:
                heapq.heappush(heap_list, (matrix[r][c + 1], r, c + 1))
            k -= 1
        return ele