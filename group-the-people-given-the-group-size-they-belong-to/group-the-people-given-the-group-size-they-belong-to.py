class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        gp = collections.defaultdict(list)
        
        for k,v in enumerate(groupSizes):
            gp[v].append(k)
            
        res = []
        for key, val in gp.items():
            idx = 0
            t = len(val)//key
            for i in range(t):
                res.append(val[idx:idx+key])
                idx += key
        return res