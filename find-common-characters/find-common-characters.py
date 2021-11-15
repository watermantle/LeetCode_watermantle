from collections import Counter
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        if len(words) == 1: return list(words[0])
        res = []
        head = Counter(words[0])
        for word in words[1:]:
            head &= Counter(word)

        return head.elements()
            