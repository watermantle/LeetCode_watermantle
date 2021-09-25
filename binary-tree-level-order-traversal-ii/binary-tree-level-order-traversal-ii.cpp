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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void DFS(TreeNode* node, int depth, vector<vector<int>>& res){
        if (!node) return;
        if (res.size() <= depth) res.push_back({});
        res[depth].push_back(node->val);
        DFS(node->left, depth + 1, res);
        DFS(node->right, depth + 1, res);
    }
};