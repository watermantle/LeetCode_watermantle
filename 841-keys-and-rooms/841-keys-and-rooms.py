from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        seen = set([0])
        queue = deque([0])
        size = len(rooms)
        while queue:
            node = queue.popleft()
            for n in rooms[node]:
                if n not in seen:
                    queue.append(n)
                    seen.add(n)
        return len(seen) == size