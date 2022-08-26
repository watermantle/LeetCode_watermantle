class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        arr = []
        for point in points:
            dis_sq = point[0] ** 2 + point[1] ** 2
            arr.append((point, dis_sq))
        arr.sort(key=lambda x: x[-1])
        
        res = []
        for i in range(k):
            res.append(arr[i][0])
        return res