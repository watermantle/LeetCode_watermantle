class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head){
            if (seen.count(head)) return true;
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};
