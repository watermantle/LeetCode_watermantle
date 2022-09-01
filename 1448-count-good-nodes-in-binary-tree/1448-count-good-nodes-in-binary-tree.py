# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        stack = [(root, float('-inf'))]
        res = 0
        while stack:
            node, max_curr = stack.pop()
            if max_curr <= node.val:
                res += 1
            if node.left:
                stack.append((node.left, max(max_curr, node.val)))
            if node.right:
                stack.append((node.right, max(max_curr, node.val)))
        return res