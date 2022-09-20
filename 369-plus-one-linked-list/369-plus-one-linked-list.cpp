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
        ListNode* new_head = reverseList(head);
        if (new_head->val <= 8) new_head->val += 1;
        else {
            ListNode* dummy_head = new ListNode(0, new_head);
            while (new_head->next && new_head->val == 9) {
                new_head->val = 0;
                new_head = new_head->next;
            }
            int val = new_head->val != 9 ? new_head->val + 1 : 1;
            cout << val << endl;
            if (new_head->val == 9) {
                new_head->next = new ListNode(val);
                new_head->val = 0;
            }
            else {
                new_head->val = val;
            }
            return reverseList(dummy_head->next);
        }
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