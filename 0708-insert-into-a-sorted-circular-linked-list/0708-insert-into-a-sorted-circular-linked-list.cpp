/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* curr = new Node(insertVal);
            curr->next = curr;
            return curr;
        };
        
        Node* curr = head;
        
        while(curr->next != head) {
            if (curr->val <= curr->next->val) {
                if (insertVal >= curr->val && insertVal <= curr->next->val) break;
            } else {
                if (insertVal >= curr->val || insertVal <= curr->next->val) break;
            }
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = new Node(insertVal, temp);
        return head;
    }
};