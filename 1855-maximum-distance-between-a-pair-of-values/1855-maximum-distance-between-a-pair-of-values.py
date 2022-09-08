class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        
        
        def binary_search(i):
            left, right = i, n2 - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums2[mid] < nums1[i]:
                    right = mid - 1
                else:
                    left = mid + 1
            return right
        
        res = 0
        for i in range(n1):
            idx = binary_search(i)
            res = max(res, idx - i)
        return res