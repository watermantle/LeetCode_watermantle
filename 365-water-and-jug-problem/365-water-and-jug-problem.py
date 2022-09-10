from collections import deque
class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        limit = jug1Capacity + jug2Capacity
        
        queue = deque([jug1Capacity, jug2Capacity,  limit])
        seen = set([jug1Capacity, jug2Capacity])
        
        while queue:
            node = queue.popleft()
            if node == targetCapacity: return True
            for n in [abs(jug1Capacity - node), jug1Capacity + node, jug2Capacity + node, abs(jug2Capacity - node)]:
                if n <= limit:
                    if n not in seen:
                        seen.add(n)
                        queue.append(n)
        return False