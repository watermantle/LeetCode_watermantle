class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        if not s: return 0
        
        count = 0
        s.sort()
        g.sort()
        
        while s and g:
            if s[-1] >= g[-1]: 
                count += 1
                s.pop(), g.pop()
            else:
                g.pop()

        return count