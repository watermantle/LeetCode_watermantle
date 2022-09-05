class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if row[0] <= target <= row[-1]:
                left, right = 0, len(row) - 1
                while left <= right:
                    mid = left + (right - left) // 2
                    if row[mid] < target: left = mid + 1
                    elif row[mid] > target: right = mid - 1
                    else:
                        return True
        return False