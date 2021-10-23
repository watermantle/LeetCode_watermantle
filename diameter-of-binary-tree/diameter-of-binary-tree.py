# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def LP(node):
            nonlocal res
            if not node: return -1
            left = LP(node.left) + 1
            right = LP(node.right) + 1
            res = max(res, left+right)
            return max(left, right)
        res = 0
        LP(root)
        return res