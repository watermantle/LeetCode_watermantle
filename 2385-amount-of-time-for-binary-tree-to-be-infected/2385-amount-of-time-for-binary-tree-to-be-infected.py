# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
from collections import defaultdict
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        # build a G
        G = defaultdict(list)
        q = [(root, -1)]
        while q:
            node, parent = q.pop()
            if parent != -1:
                G[parent].append(node.val)
                G[node.val].append(parent)
            if node.left: q.append((node.left, node.val))
            if node.right: q.append((node.right, node.val))
        
        # bfs part
        que = deque([start])
        seen = set()
        seen.add(start)
        res = 0
        
        while que:
            n = len(que)
            while n:
                node = que.popleft()
                for v in G[node]:
                    if v not in seen:
                        que.append(v)
                        seen.add(v)
                n -= 1
            res += 1
        return res - 1