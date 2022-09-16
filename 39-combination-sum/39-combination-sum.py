class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        
        def backtrack(curr, arr, start):
            if curr == 0:
                res.append(list(arr))
                return
            elif curr < 0:
                return
            
            for i in range(start, len(candidates)):
                arr.append(candidates[i])
                backtrack(curr - candidates[i], arr, i)
                arr.pop()
        
        backtrack(target, [], 0)
        return res