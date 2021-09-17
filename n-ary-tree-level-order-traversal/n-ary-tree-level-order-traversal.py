"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        def helper(root, depth, res):
            if not root: return []
            while len(res) <= depth: res.append([])
                
            res[depth].append(root.val) 
            for child in root.children:
                helper(child, depth+1, res)
        
        res = []
        helper(root, 0, res)
        return res
            