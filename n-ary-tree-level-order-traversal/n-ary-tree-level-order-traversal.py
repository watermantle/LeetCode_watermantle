"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        # iterating approach with queue
        
        if not root : return []
        queue = [root]
        depth = 0
        res = []
        
        while queue:
            size = len(queue)
            temp = []
            while size:
                size -= 1
                node = queue.pop(0)
                temp.append(node.val)
                for child in node.children:
                    queue.append(child)
            res.append(temp)
            depth += 1
        return res