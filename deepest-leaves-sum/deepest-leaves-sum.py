# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        self.max_depth = 0
        
        def dfs(node=root, d=0):
            if not node: return
            
            if self.max_depth < d:
                self.max_depth = d
                self.res = 0
            if d == self.max_depth: 
                self.res += node.val
            
            dfs(node.left, d+1)
            dfs(node.right, d+1)
            
        dfs()
        return self.res
