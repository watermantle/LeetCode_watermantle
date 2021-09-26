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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        int case1 = pathWithRoot(root, targetSum);
        int case2 = pathSum(root->left, targetSum);
        int case3 = pathSum(root->right, targetSum);
        
        return case1 + case2 + case3;
    }
private:
    int pathWithRoot(TreeNode* root, int targetSum){
        if (!root) return 0;
        
        int res1 = pathWithRoot(root->left, targetSum - root->val);
        int res2 = pathWithRoot(root->right, targetSum - root->val);
        int res;
        res = res1 + res2;
        if (root->val == targetSum) res = res1 + res2 + 1;
        return  res;
    }
};