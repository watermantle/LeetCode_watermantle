/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        UnivaluePath(root, res);
        return res;
    }
private:
    int UnivaluePath(TreeNode* node, int& res){
        if (!node) return 0;
        int l = UnivaluePath(node->left, res);
        int r = UnivaluePath(node->right, res);
        int lpl = 0;
        int lpr = 0;
        if (node->left && node->val == node->left->val) lpl = l + 1;
        if (node->right && node->val == node->right->val) lpr = r + 1;
        res = max(res, lpl + lpr);
        return max(lpl, lpr);
    }
};
