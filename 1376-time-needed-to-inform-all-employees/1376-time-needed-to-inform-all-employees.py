from collections import deque
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        res = 0
        queue = deque([(headID, informTime[headID])])
        
        G = collections.defaultdict(list)
        for i, m in enumerate(manager):
            if m != -1:
                G[m].append(i)
        res = 0
        while queue:
            size = len(queue)
            while size:
                node, dur = queue.popleft()
                for i in G[node]:
                    res = max(res, dur + informTime[i])
                    queue.append((i, dur + informTime[i]))
                size -= 1
        return res 