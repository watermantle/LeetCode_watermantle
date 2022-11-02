from collections import deque
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        def mutable(s1, s2):
            res = 0
            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    res += 1
            return res == 1
        
        G = collections.defaultdict(list)
        for s1 in [start] + bank:
            for s2 in bank:
                if s1 != s2 and mutable(s1, s2):
                    G[s1].append(s2)
        
        queue = deque([(start, 0)])
        seen = set([start])
        
        while queue:
            size = len(queue)
            while size:
                size -= 1
                node, n = queue.popleft()
                if node == end: return n
                for v in G[node]:
                    if v not in seen:
                        queue.append((v, n + 1))
                        seen.add(v)
        return -1