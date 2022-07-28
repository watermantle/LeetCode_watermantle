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
        stack<int> stk1;
        stack<int> stk2;
        
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head = nullptr;
        int carry = 0, sum;
        
        while (!stk1.empty() || !stk2.empty() || carry) {
            sum = (!stk1.empty() ? stk1.top() : 0) + (!stk2.empty() ? stk2.top() : 0) + carry;
            ListNode* tail = new ListNode(sum % 10);
            carry = sum / 10;
            if (!stk1.empty()) stk1.pop();
            if (!stk2.empty()) stk2.pop();
            tail->next = head;
            head = tail;
        }
        return head;
    }
};