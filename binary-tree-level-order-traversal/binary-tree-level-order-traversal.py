# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # BFS approach
        if not root: return []
        curr = [root] # curr list to store the node needed to be visit
        res = []
        
        while curr:
            next_ = []
            res.append([])
            for node in curr:
                res[-1].append(node.val)
                if node.left: next_.append(node.left)
                if node.right: next_.append(node.right)
            curr = next_
        return res