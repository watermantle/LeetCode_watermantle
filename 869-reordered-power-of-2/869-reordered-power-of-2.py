class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        return any(x[0] != '0' and bin(int(''.join(x))).count('1') == 1 for x in itertools.permutations(str(n)))