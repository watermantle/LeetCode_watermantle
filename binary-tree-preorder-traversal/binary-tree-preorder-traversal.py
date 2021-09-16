# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # iterating approach
        stack = []
        res = []
        curr = root
        
        while curr or len(stack) != 0:
            if curr:
                stack.append(curr)
                res.append(curr.val)
                curr = curr.left
            else:
                curr = stack.pop().right
                
        return res