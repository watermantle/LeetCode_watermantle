class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        
        if not tokens or tokens[0] > power:
            return 0
        
        left, right = 0, len(tokens) - 1
        res = 0
        score = 0
        
        while left <= right:
            if power >= tokens[left]:
                score += 1
                power -= tokens[left]
                left += 1
                res = max(res, score)
            elif power < tokens[left] and score > 0:
                score -= 1
                power += tokens[right]
                right -= 1
            else:
                return res
        return res