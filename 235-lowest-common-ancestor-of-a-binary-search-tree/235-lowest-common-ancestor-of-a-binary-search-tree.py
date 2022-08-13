# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return root
        
        present_val = root.val
        p_val = p.val
        q_val = q.val
        
        if present_val > p_val and present_val > q_val:
            return self.lowestCommonAncestor(root.left, p, q)
        if present_val < p_val and present_val < q_val:
            return self.lowestCommonAncestor(root.right, p, q)
        
        return root
        