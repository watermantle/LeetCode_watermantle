class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        # just copy and paste from solution, don't like this
        res = 0
        
        for num in data:
            bin_rep = format(num, "#010b")[-8:]
            if res == 0:
                for bit in bin_rep:
                    if bit == '0': break
                    res += 1
                if res == 0: continue
                
                if res == 1 or res > 4: return False
            else:
                if not (bin_rep[0] == '1' and bin_rep[1] == '0'): return False
                
            res -= 1
        
        return res == 0