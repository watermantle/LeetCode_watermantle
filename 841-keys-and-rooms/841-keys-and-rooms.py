from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        seen = set([0])
        stack = [0]
        size = len(rooms)
        while stack:
            node = stack.pop()
            for n in rooms[node]:
                if n not in seen:
                    stack.append(n)
                    seen.add(n)
        return len(seen) == size