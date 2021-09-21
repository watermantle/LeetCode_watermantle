# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        res = 0
        max_depth = 0
        
        def dfs(node=root, d=0):
            nonlocal res, max_depth
            if not node: return
            
            if max_depth < d:
                max_depth = d
                res = 0
            if d == max_depth: 
                res += node.val
            
            dfs(node.left, d+1)
            dfs(node.right, d+1)
            
        dfs()
        return res
