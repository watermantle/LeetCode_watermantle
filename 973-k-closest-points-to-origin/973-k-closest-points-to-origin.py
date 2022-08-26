from queue import PriorityQueue
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        pq = PriorityQueue()
        for point in points:
            dis_sq = point[0] ** 2 + point[1] ** 2
            pq.put((dis_sq, point))
        
        res = []
        for _ in range(k):
            item = pq.get()
            res.append(item[1])
        return res
        
        