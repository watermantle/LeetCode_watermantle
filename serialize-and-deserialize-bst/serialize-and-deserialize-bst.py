class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
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

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
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