# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def balance(node):
            nonlocal res
            if not node: return 0
            left = balance(node.left)
            right = balance(node.right)
            res += abs(left) + abs(right)
            
            return node.val - 1 + left + right
        
        res = 0
        balance(root)
        return res 
    
        