/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast) {
            if (!fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) break;
        }
        
        if (!fast) return nullptr;
        
        while (true) {
            if (slow == head) return slow;
            slow = slow->next;
            head = head->next;
        }
    }
};