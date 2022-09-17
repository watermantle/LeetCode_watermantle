class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        def valid_prefixes(word):
            res = []
            for i in range(len(word)):
                if word[i:] == word[i:][::-1]:
                    res.append(word[:i])
            return res
        
        def valid_suffixes(word):
            res = []
            for i in range(len(word)):
                if word[:i + 1] == word[:i + 1][::-1]:
                    res.append(word[i + 1:])
            return res
        
        word_lookup = {word: i for i, word in enumerate(words)}
        res = []
        for i, word in enumerate(words):
            reverse = word[::-1]
            
            if reverse in word_lookup and i != word_lookup[reverse]:
                res.append([i, word_lookup[reverse]])
            
            for suffix in valid_suffixes(word):
                reversed_suffix = suffix[::-1]
                if reversed_suffix in word_lookup:
                    res.append([word_lookup[reversed_suffix], i])
            
            for prefix in valid_prefixes(word):
                preversed_prefix = prefix[::-1]
                if preversed_prefix in word_lookup:
                    res.append([i, word_lookup[preversed_prefix]])
        return res