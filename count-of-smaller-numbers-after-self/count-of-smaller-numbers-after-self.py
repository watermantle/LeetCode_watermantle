import numpy as np

class Solution:
    def countSmaller(self, nums):
            deque_ = collections.deque() 
            res = [] 
            for num in nums[::-1]:
                idx = bisect.bisect_left(deque_, num)
                res += idx,
                deque_.insert(idx, num)
            return res[::-1]