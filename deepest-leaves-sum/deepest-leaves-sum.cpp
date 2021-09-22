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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, max_depth = 0;
        
        function<void(TreeNode*, int)> dfs = [&] (TreeNode* node, int depth){
            if (!node) return;
            if (max_depth < depth) {
                max_depth = depth;
                res = 0;
            };
            if (depth == max_depth){
                res += node->val;
            }
            dfs(node->left, depth + 1);
            dfs(node->right, depth +1);
        };
            
        dfs(root, 0);
        return res;
            
    }

};