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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> v;
            root = dfs(root, v);
            res.push_back(v);
        }
        return res;
    }
private:
    TreeNode* dfs(TreeNode* root, vector<int>& v) {
        if (!root) return root;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return nullptr;
        }
        root->left = dfs(root->left, v);
        root->right = dfs(root->right, v);
        return root;
    }
}; 