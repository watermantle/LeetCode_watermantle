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
        ListNode dummy_head(0);
        dummy_head.next = head;
        head = &dummy_head;
        
        ListNode* n1;
        ListNode* n2;
        
        while (head->next && head->next->next){
            n1 = head->next;
            n2 = head->next->next;
            
            n1->next = n2->next;
            n2->next = n1;
            head->next = n2;
            
            // head points to n1
            head = n1;
        }
        return dummy_head.next;
    }
};
