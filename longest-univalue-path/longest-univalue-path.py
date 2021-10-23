# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        res = 0
        def UnivaluePath(node):
            nonlocal res
            if not node: return 0
            left = UnivaluePath(node.left)
            right = UnivaluePath(node.right)
            lpl = 0
            lpr = 0
            if node.left and node.val == node.left.val: lpl = left + 1
            if node.right and node.val == node.right.val: lpr = right + 1
            res = max(res, lpl + lpr)
            return max(lpl, lpr)
        if not root: return 0
        UnivaluePath(root)
        
        return res