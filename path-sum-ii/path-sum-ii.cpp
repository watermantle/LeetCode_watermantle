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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(root, targetSum, curr, res);
        
        return res;
    }
private:
    void helper(TreeNode* root, int targetSum, vector<int>& curr, vector<vector<int>>& res){
        if (!root) return;
        if (!root->left && !root->right) {
            if (root->val == targetSum){
                //  this will copy curr and don't hurt curr when push val to curr
                res.push_back(curr);
                res.back().push_back(root->val);
            }
            return;
        }
        curr.push_back(root->val);
        targetSum -= root->val;
        helper(root->left, targetSum, curr, res);
        helper(root->right, targetSum, curr, res);
        curr.pop_back();
    }
};