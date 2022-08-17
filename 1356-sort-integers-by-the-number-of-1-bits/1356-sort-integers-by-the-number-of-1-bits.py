class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        dic = collections.defaultdict(int)
        for num in arr:
            dic[num] = bin(num).count('1')
        
        arr.sort()
        arr.sort(key=lambda x: dic[x])
        return arr