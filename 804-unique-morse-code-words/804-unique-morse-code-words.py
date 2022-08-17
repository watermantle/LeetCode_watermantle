class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        alph = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        res = set()
        for word in words:
            morse = ""
            for char in word:
                morse += alph[ord(char) - ord('a')]
            res.add(morse)
        return len(res)
        