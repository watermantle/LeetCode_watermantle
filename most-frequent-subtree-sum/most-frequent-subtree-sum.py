# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        
        def helper(node):
            if not node: return 0
            _sum = node.val + helper(node.left) + helper(node.right)
            dic[_sum] += 1
            return _sum
        dic = collections.Counter()
        helper(root)
        max_count = max(dic.values())
        return [val for val in dic.keys() if dic[val] == max_count]