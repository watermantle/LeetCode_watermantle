import numpy as np
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(set(nums)) == 1: return 1
        
        diff1 = nums[1] - nums[0]
        
        while diff1 == 0 and len(nums) > 2:
            nums.pop(0)
            diff1 = nums[1] - nums[0]
            
        sign = (diff1 > 0) * 2 - 1
        count = 2
        
        for i in range(2, len(nums)):
            diff = nums[i] - nums[i - 1]
                
            if diff * sign < 0:
                count += 1
                sign = -sign
                
        return count