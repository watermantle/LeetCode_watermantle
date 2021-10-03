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
    vector<string> res;
    string s;
    
    vector<string> binaryTreePaths(TreeNode* root) {    
        preorder(root, 0);
        return res;
    }
private:
    void preorder(TreeNode* node, int len){
        if (!node) return;
        
        s += (len > 0 ? "->" : "") + to_string(node->val);
        if (!node->left && !node->right){
            res.push_back(s);
        };
        preorder(node->left, s.size());
        preorder(node->right, s.size());
        while (len != s.size()) s.pop_back();
    }
};