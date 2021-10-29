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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy_head(0);
        ListNode* tail = &dummy_head;
        
        int sum_, carry = 0;
        
        while (l1 || l2 || carry){
            sum_ = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            tail->next = new ListNode(sum_ % 10);
            tail = tail->next;
            carry = sum_ / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy_head.next;
    }
};
