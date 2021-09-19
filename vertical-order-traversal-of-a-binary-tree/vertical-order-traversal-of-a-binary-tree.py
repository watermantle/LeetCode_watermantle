# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        vals = []
        res = []
        
        def dfs(root,col, row):
            if not root: return
            vals.append((col, row, root.val))
            # search left, row-- and col++
            dfs(root.left, col-1, row+1)
            dfs(root.right, col+1, row+1)
        
        dfs(root, 0, 0)
        most_left = -1000
        
        for c, r, val in sorted(vals):
            if most_left != c: 
                most_left = c
                res.append([])
            res[-1].append(val)
        return res