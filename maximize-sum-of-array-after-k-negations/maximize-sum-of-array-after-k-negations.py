class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        for _ in range(k):
            nums.sort()
            nums[0] = -nums[0]
        return sum(nums)