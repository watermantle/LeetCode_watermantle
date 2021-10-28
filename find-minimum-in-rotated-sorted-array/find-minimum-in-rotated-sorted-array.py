class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 2:
            return min(nums)
        if len(nums) == 1:
            return nums[0]
        mid = int(len(nums) / 2)
        if nums[0] < nums[-1]: return nums[0]
        return min(self.findMin(nums[:mid]),
                  self.findMin(nums[mid:]))