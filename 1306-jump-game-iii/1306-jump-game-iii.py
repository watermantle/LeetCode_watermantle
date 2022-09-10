from collections import defaultdict, deque
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        G = defaultdict(list)
        n = len(arr)
        if arr[start] == 0: return True
        
        for i, num in enumerate(arr):
            if num != 0:
                if i + num < n:
                    G[(i, num)].append((i + num, arr[i + num]))
                if i - num >= 0:
                    G[(i, num)].append((i - num, arr[i - num]))
        
        queue = deque([(start, arr[start])])
        seen = set([(start, arr[start])])

        while queue:
            idx, num = queue.popleft()
            if num == 0: 
                return True
            for node in G[(idx, num)]:
                if node not in seen:
                    seen.add(node)
                    queue.append(node)
        return False