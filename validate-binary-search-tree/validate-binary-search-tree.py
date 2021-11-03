# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node, min_val, max_val):
        if not node: return True
        if node.val <= min_val or node.val >= max_val: return False
        return self.helper(node.left, min_val, node.val) and self.helper(node.right, node.val, max_val)
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        min_val = -float('inf')
        max_val = float('inf')
        return self.helper(root, min_val, max_val)
        
    