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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> mp;
        queue<int> memo;
        while (head) {
            mp[head->val] += 1;
            memo.push(head->val);
            head = head->next;
        }
        
        ListNode* dummy_head = new ListNode();
        ListNode* curr = dummy_head;
        
        while (!memo.empty()) {
            int val = memo.front(); memo.pop();
            if (mp[val] == 1) {
                curr->next = new ListNode(val, nullptr);
                curr = curr->next;
            }
        }
        return dummy_head->next;
    }
};