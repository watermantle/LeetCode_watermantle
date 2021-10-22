# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        res = ''
        def dfs(node):
            nonlocal res
            if not node: 
                res = res + " #"
                return
            res = res + " {}".format(node.val)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return res

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        data = data.split(' ')[1:]
        def helper(data):
            val = data.pop(0)
            if val == "#": return None
            node = TreeNode(val)
            node.left = helper(data)
            node.right = helper(data)
            return node
        return helper(data)

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans