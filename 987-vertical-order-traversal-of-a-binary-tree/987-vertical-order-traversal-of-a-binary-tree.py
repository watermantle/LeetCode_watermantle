# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        
        res = collections.defaultdict(list)
        vals = []
        
        def dfs(node, row, col):
            if not node: return
            vals.append((col, row, node.val))
            
            dfs(node.left, row + 1, col - 1)
            dfs(node.right, row + 1, col + 1)
            
        dfs(root, 0, 0)
        for c, r, val in sorted(vals):
            res[c].append(val)
        return res.values()
