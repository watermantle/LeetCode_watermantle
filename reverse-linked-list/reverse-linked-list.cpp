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
    ListNode* reverseList(ListNode* head) {
        stack<int> stack0;
        
        while (head){
            stack0.push(head->val);
            head = head->next;
        }
        
        ListNode dummy_head(0);
        ListNode* tail = &dummy_head;
        
        while (!stack0.empty()){
            tail->next = new ListNode(stack0.top());
            stack0.pop();
            tail = tail->next;
        }
        return dummy_head.next;
    }
};