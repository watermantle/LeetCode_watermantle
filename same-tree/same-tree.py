# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def preorder(node, res):
            if not node: return
            res.append(node.val)
            if node.left: 
                preorder(node.left, res)
            else:
                res.append(None)
            if node.right: 
                preorder(node.right, res)
            else:
                res.append(None)
        resp = []
        resq = []
        
        preorder(p, resp)
        preorder(q, resq)
        
        return resp==resq
            