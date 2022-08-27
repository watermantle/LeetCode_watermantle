from collections import deque

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        # iterating approach with queue
        res = []
        if not root: return res
        queue = deque([root])
        
        while queue:
            size = len(queue)
            temp = []
            while size:
                node = queue.popleft()
                temp.append(node.val)
                for child in node.children:
                    queue.append(child)
                size -= 1
            res.append(temp)
        return res
        