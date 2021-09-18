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
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        
        vector<int> res;
        vector<Node*> stack;
        stack.push_back(root);
        
        while (!stack.empty()){
            Node* node = stack[stack.size() - 1];
            stack.pop_back();
            res.push_back(node->val);
            
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++){
                stack.push_back(*it);
            }
        }
        return res;
    }
};