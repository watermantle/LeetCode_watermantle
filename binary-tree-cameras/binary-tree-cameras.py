# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        # for the state: None = 0, Covered = 1, Camera = 2
        res = 0
        def dfs(node):
            nonlocal res
            if not node: return 1
            left = dfs(node.left)
            right = dfs(node.right)
            
            if left == 0 or right == 0:
                res += 1
                return 2
            if left == 2 or right == 2:
                return 1
            return 0
        
        if dfs(root) == 0: res += 1
        return res