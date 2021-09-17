/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }

public:
    void helper(Node* root, int depth, vector<vector<int>>& res){
        if (root == nullptr) return;
        
        while (res.size() <= depth) res.push_back({});
        res[depth].push_back(root->val);
        
        for (auto child : root->children){
            helper(child, depth+1, res);
        }
    }
};