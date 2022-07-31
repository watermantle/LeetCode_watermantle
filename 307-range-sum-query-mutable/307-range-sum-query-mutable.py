class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.len = int(math.ceil(len(nums) / math.sqrt(len(nums))))
        self.memo = [0] * self.len
        for i in range(len(nums)):
            self.memo[int(i / self.len)] += nums[i]
        
    def update(self, index: int, val: int) -> None:
        idx = int(index / self.len)
        self.memo[idx] = self.memo[idx] - self.nums[index] + val
        self.nums[index] = val

    def sumRange(self, left: int, right: int) -> int:
        sum_ = 0
        start = int(left / self.len)
        end = int(right / self.len)
        if start == end:
            for i in range(left, right + 1):
                sum_ += self.nums[i]
        else:
            left_bound = (start + 1) * self.len
            right_bound = end * self.len
            
            for i in range(left, left_bound):
                sum_ += self.nums[i]
            for i in range(start + 1, end):
                sum_ += self.memo[i]
            for i in range(right_bound, right + 1):
                sum_ += self.nums[i]
        return sum_

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)