/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* cur = dummy;
        
        ListNode* n1;
        ListNode* n2;
        
        while (cur->next && cur->next->next) {
            n1 = cur->next;
            n2 = cur->next->next;
            
            n1->next = n2->next;
            n2->next = n1;
            cur->next = n2;
            
            cur = n1;
        }
        return dummy->next;
    }
};