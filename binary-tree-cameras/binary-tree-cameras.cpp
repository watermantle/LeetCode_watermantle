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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        // check if the input is [0]
        if (dfs(root, res) == 0) ++res;
        return res;
    }
private:
    int dfs(TreeNode* node, int& res){
        if (!node) return 1;
        int left = dfs(node->left, res);
        int right = dfs(node->right, res);
        
        if (left == 0 || right == 0){
            ++res;
            return 2;
        }
        if (left == 2 || right == 2) return 1;
        return 0;
    }
};
