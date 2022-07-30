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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // comp to compare two listnode
        auto comp = [](ListNode* n1, ListNode* n2) {return n1->val > n2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        
        for (auto list: lists) {
            if (list) pq.push(list);
        }
        while (!pq.empty()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return dummy->next;
    }
};