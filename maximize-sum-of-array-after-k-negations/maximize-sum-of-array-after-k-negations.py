from queue import PriorityQueue

class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()
        for num in nums: pq.put(num)
        for i in range(k):
            num = pq.get()
            pq.put(-num)
        return sum([pq.get() for  _ in range(len(nums))])