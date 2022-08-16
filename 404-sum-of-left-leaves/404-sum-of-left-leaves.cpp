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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return preorder(root, false);
    }
private:
    int preorder(TreeNode* node, bool ifLeft) {
        if (!node->left && !node->right) {
            return ifLeft ? node->val : 0;
        }
        int sum = 0;
        if (node->left) sum += preorder(node->left, true);
        if (node->right) sum += preorder(node->right, false);
        return sum;
    }
};