class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        res = " ".join(word[::-1] for word in words)
        return res