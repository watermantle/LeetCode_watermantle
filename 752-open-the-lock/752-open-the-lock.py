from collections import deque
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next_comb(curr):
            for i in range(4):
                x = int(curr[i])
                for d in (-1, 1):
                    y = (x + d) % 10
                    yield curr[:i] + str(y) + curr[i + 1:]
        
        if sorted(next_comb(target)) == sorted(deadends):
            return -1
        
        queue = deque([('0000', 0)])
        deads = set(deadends)
        seen = set(['0000'])
        
        while queue:
            node, times = queue.popleft()
            if node == target:
                return times
            if node in deads:
                continue
            for comb in next_comb(node):
                if comb not in seen:
                    seen.add(comb)
                    queue.append((comb, times + 1))
        return -1