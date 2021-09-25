# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot: return True
        
        def sameTree(node1, node2):
            if not node1 and not node2: return True
            if not node1 or not node2: return False
            
            return all((node1.val == node2.val, 
                       sameTree(node1.left, node2.left),
                       sameTree(node1.right, node2.right)))
        
        def inorder(node, value, nodes=[]):
            if not node: return
            
            if node.val == value: nodes.append(node)
            inorder(node.left, value, nodes)
            inorder(node.right, value, nodes)
        
        nodes = []
        inorder(root, subRoot.val, nodes)
        
        res = []
        for node in nodes:
            res.append(sameTree(node, subRoot))
        
        return any(res)