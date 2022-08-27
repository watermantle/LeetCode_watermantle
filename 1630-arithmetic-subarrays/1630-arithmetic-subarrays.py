class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        for i in range(len(l)):
            temp = nums[l[i]: r[i] + 1]
            temp.sort()
            j = 2
            while j < len(temp):
                if temp[j] - temp[j - 1] != temp[1] - temp[0]:
                    break
                j += 1
            res.append(j == len(temp))
        return res
            