from collections import deque
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        limit = 2000 + a + b
        seen = set(forbidden)
        # (idx, 0/1), the second var means 0 if back or 1 if forward
        queue = deque([(0, 1)])
        res = 0
        
        while queue:
            size = len(queue)
            while size:
                size -= 1
                position, direct = queue.popleft()
                if position == x: return res
                if position not in seen:
                    seen.add(position)
                    # can jump backward only if pre is forward
                    if direct == 1:
                        next_pos = position - b
                        if next_pos >= 0:
                            queue.append((next_pos, 0))
                    next_pos = position + a
                    if next_pos <= limit:
                        queue.append((next_pos, 1))
            res += 1
        return -1