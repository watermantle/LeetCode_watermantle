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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prev = dummyHead;
        
        while (prev->next != nullptr) {
            if (prev->next->val == val) {
                ListNode* temp = prev->next;
                prev->next = prev->next->next;
                delete temp; 
            } else prev = prev->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};