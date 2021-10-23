# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        def dfs(node):
            if not node: return 0, 0, 0
            l, ll, lr = dfs(node.left)
            r, rl, rr = dfs(node.right)
            return max(node.val + ll + lr + rl + rr, l + r), l, r
        return dfs(root)[0]
            