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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        int base = 1;
        stack<int> stk;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }
        
        while (!stk.empty()) {
            int num = stk.top(); stk.pop();
            res += num * base;
            base *= 2;
        }
        return res;
    }
};