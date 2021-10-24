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
    int distributeCoins(TreeNode* root) {
        balance(root, res);
        return res;
    }
private:
    int res = 0;
    int balance(TreeNode* node, int& res){
        if (!node) return 0;
        int left = balance(node->left, res);
        int right = balance(node->right, res);
        res += abs(left) + abs(right);
        return node->val - 1 + left + right;
    }
};
