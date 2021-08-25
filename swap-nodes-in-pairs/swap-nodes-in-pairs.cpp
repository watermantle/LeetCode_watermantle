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
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *n0, *n1;

        n0 = head;
        n1 = head->next;

        while (n0 && n1){
            int temp_val;

            temp_val = n0->val;
            n0->val = n1->val;
            n1->val = temp_val;
            
            if (n0->next == NULL){break;};
            n0 = n0->next->next;
            
            if (n1->next == NULL){break;};
            n1 = n1->next->next;
    }
    return head;
    }
};