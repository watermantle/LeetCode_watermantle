class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if not s: return False
        res = (s + s)[1: -1]
        return res.find(s) != -1