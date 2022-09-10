class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        res = set(range(n))
        
        for e in edges:
            if e[1] in res:
                res.remove(e[1])
        return res