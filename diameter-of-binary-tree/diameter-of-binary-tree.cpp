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
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }

private:
    int res;
    int helper(TreeNode* node){
        if (!node) return -1;
        int left = helper(node->left) + 1;
        int right = helper(node->right) + 1;
        res = max(res, left + right);
        return max(left, right);
    }
};
