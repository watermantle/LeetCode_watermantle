# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # iterating using Stack
        stack = []
        res = []
        
        tree_curr = root
        while tree_curr or len(stack) != 0:
            while tree_curr:
                stack.append(tree_curr)
                tree_curr = tree_curr.left
                
            tree_curr = stack.pop()
            res.append(tree_curr.val)
            tree_curr = tree_curr.right
        
        return res