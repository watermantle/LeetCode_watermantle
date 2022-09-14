# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        stack = [(root, 0)]
        res = 0
        while stack:
            node, idx = stack.pop()
            
            if node:
                idx ^= (1 << node.val)
                
                if not node.left and not node.right:
                    if idx & (idx - 1) == 0:
                        res += 1
                else:
                    stack.append((node.right, idx))
                    stack.append((node.left, idx))
        return res