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
    int rob(TreeNode* root) {
        if (!root) return 0;
        int l = 0, r = 0;
        return helper(root, l, r);
    }
private:
    int helper(TreeNode* node, int& l, int& r){
        if (!node) return 0;
        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        
        l = helper(node->left, ll, lr);
        r = helper(node->right, rl, rr);
        
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};
