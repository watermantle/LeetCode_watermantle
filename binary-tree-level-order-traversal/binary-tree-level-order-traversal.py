# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def helper(node, depth, res):
            if not node: return []
            
            if len(res) <= depth: res.append([])
            res[depth].append(node.val)
            
            helper(node.left, depth+1, res)
            helper(node.right, depth+1, res)
            
        res = []
        helper(root, 0, res)
        return res