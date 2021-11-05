import numpy as np
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        res = []
        def in_order(node):
            if not node: return
            if node.left: in_order(node.left)
            res.append(node.val)
            if node.right: in_order(node.right)
        
        in_order(root)
        
        return min(np.abs(np.diff(res)))