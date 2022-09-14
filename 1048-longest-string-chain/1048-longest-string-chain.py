class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        
        def chained(word1, word2):
            word1 = list(word1)
            word2 = list(word2)
            for i in range(len(word1)):
                if word1[i] != word2[i]:
                    word2.pop(i)
                    return word1 == word2
            word2.pop()
            return word1 == word2
        
        n = len(words)
        dp = [1] * n
        
        for i in range(1, n):
            word = words[i]
            for j in range(i):
                if chained(words[j], word):
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)