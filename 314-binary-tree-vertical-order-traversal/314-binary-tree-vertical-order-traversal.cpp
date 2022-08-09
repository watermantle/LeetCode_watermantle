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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> colTable;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<vector<int>> res;
        
        while (!q.empty()) {
            pair<TreeNode*, int> item;
            item = q.front(); q.pop();
            
            TreeNode* node = item.first;
            int col = item.second;
            
            if (node) {
                colTable[col].push_back(node->val);
                q.push({node->left, col - 1});
                q.push({node->right, col + 1});
            }
        }
        for (auto& item: colTable) res.push_back(item.second);
        return res;
    }
};