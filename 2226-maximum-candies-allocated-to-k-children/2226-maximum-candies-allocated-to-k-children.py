class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        low, high = 1, max(candies)
        
        if sum(candies) < k: return 0 
        
        def find_part(pile_size):
            count = 0
            for candy in candies:
                count += candy // pile_size
            return count >= k
        
        while low <= high:
            mid = low + (high - low) // 2
            if find_part(mid):
                res = mid
                low = mid + 1
            else:
                high = mid - 1
                
        return res
        
        