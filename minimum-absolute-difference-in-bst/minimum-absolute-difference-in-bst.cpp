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
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        
        int min_diff = sorted.back();
        for (int i = 1; i < sorted.size(); ++i){
            min_diff = min(min_diff, sorted[i] - sorted[i - 1]);
        }
        return min_diff;
    }
private:
    void inorder(TreeNode* node, vector<int>& sorted){
        if (!node) return;
        if (node->left) inorder(node->left, sorted);
        sorted.push_back(node->val);
        if (node->right) inorder(node->right, sorted);
    }
};
