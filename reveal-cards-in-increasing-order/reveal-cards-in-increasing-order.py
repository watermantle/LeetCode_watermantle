class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        res = []
        while deck:
            if len(res) == 0:
                res.append(deck.pop(-1))
            else:
                res.insert(0, res.pop(-1))
                res.insert(0, deck.pop(-1))
        return res