# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        # time complexity of O(n^2)
        def pathwithRoot(root, targetSum):
            if not root: return 0
            res1 = pathwithRoot(root.left, targetSum - root.val)
            res2 = pathwithRoot(root.right, targetSum - root.val)
            res = res1 + res2
            if root.val == targetSum:
                res = res1 + res2 + 1
            return res
        
        if not root: return 0
        case1 = pathwithRoot(root, targetSum)
        case2 = self.pathSum(root.left, targetSum)
        case3 = self.pathSum(root.right, targetSum)
        
        return case1 + case2 + case3