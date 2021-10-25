import numpy as np

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return int(np.median(np.array(nums)))