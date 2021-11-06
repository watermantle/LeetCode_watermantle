import numpy as np
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) == 1: return 1
        
        diff1 = nums[1] - nums[0]
        idx = 0
        while diff1 == 0 and idx < len(nums) - 2:
            idx += 1
            diff1 = nums[idx + 1] - nums[idx]
            
        sign = (diff1 > 0) * 2 - 1
        
        if diff1 == 0: count = 1
        else: count = 2
        
        for i in range(2+idx, len(nums)):
            diff = nums[i] - nums[i - 1]
                
            if (diff > 0 and sign < 0) or (diff <0 and sign >0):
                count += 1
                sign = -sign
                
        return count