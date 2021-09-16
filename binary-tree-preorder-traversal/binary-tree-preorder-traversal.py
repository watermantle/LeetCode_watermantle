# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # recursive approach
        def helper(root, res):
            
            if root:
                res.append(root.val)
            
            if root:
                helper(root.left, res)
            if root:
                helper(root.right, res)
        
            return res
    
        res = []
        
        helper(root, res)
        
        return res