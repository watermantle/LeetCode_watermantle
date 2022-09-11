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
        
        seen = set([start])
        queue = deque([(start, 0)])
        
        res = 0
        while queue:
            node, mut = queue.popleft()
            if node == end:
                return mut
            for v in G[node]:
                if v not in seen:
                    seen.add(v)
                    queue.append((v, mut + 1))
        return -1