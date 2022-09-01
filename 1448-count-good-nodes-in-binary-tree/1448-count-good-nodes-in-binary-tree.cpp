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
    int res = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }
private:
    void dfs(TreeNode* node, int maxCurr) {
        if (maxCurr <= node->val) res++;
        
        if (node->left) {
            dfs(node->left, max(maxCurr, node->val));
        }
        if (node->right) {
            dfs(node->right, max(maxCurr, node->val));
        }
    }
};