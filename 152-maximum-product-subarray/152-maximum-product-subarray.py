class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 0
        
        curr_max = nums[0]
        curr_min = nums[0]
        res = curr_max
        
        for i in range(1, len(nums)):
            curr = nums[i]
            temp = max(curr_max * curr, curr_min * curr, curr)
            curr_min = min(curr_max * curr, curr_min * curr, curr)
            curr_max = temp
            res = max(curr_max, res)
            
        return res