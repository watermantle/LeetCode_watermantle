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
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        
        ListNode* new_head = reverseList(head);
        int carry = 1;
        ListNode* curr = new_head;
        while (curr && carry != 0) {
            int val = curr->val + carry;
            carry = val > 9 ? 1 : 0;
            curr->val = val % 10;
            curr = curr->next;
        }
        if (carry > 0) head->next = new ListNode(carry);
        return reverseList(new_head);
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};