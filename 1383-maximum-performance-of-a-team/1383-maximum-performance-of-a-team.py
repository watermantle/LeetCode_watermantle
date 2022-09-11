class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        modulo = 10 ** 9 + 7
        
        eff_sp = zip(efficiency, speed)
        eff_sp = sorted(eff_sp, key=lambda x: x[0], reverse=True)
        
        speed_heap = []
        speed_sum, res = 0, 0
        
        for curr_ef, curr_speed in eff_sp:
            if len(speed_heap) > k - 1:
                speed_sum -= heapq.heappop(speed_heap)
            heapq.heappush(speed_heap, curr_speed)
            
            speed_sum += curr_speed
            res = max(res, speed_sum * curr_ef)
        return res % modulo