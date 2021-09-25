# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def DFS(node, leves):
            if not node: return
            
            if not node.left and not node.right: leves.append(node.val)
            
            if node.left: DFS(node.left, leves)
            if node.right: DFS(node.right, leves)
        
        leves1 = []
        leves2 = []
        
        DFS(root1, leves1)
        DFS(root2, leves2)
        
        return leves1 == leves2