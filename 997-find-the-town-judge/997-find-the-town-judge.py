class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1: return 1
        
        tt = collections.defaultdict(int)
        te = collections.defaultdict(int)
        
        for trest, trestee in trust:
            te[trestee] += 1
            tt[trest] += 1
        
        for t in te.keys():
            if te[t] == n - 1 and tt[t] == 0:
                return t
        return -1