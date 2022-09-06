class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        arr.sort()
        if 0 in arr:
            arr.remove(0)
        n = len(arr)
        def binary_search(i):
            left, right = 0, n - 1
            target = 2 * i
            while left <= right:
                mid = left + (right - left) // 2
                if arr[mid] < target: left = mid + 1
                elif arr[mid] > target: right = mid - 1
                else:
                    return True
            return False
        
        for i, num in enumerate(arr):
            if binary_search(num):
                return True
        return False