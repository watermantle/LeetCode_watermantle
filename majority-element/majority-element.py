class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        C = Counter(nums)
        for key, val in C.items():
            if val > len(nums) / 2: return key