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
        stack<int> stack1;
        stack<int> stack2;
        
        while (l1){
            stack1.push(l1->val);
            l1 = l1->next;
        }
        while (l2){
            stack2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head = nullptr;
        
        int carry = 0, sum_;
        while (!stack1.empty() || !stack2.empty() || carry){
            sum_ = (!stack1.empty() ? stack1.top() : 0) + (!stack2.empty() ? stack2.top() : 0) + carry;
            ListNode* tail = new ListNode(sum_ % 10);
            carry = sum_ / 10;
            if (!stack1.empty()) stack1.pop();
            if (!stack2.empty()) stack2.pop();
            tail->next = head;
            head = tail;
        }
        return head;
    }
};
