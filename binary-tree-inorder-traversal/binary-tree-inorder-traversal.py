# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        # Recursive Approach
        def helper(root, res):
            if root:
                if root.left:
                    helper(root.left, res)
                
                res.append(root.val)
                
                if root.right:
                    helper(root.right, res)
        res = []
        helper(root, res)
        return res
        
        