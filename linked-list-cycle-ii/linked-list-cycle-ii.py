# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        
        while fast:
            if not fast.next: return None
            fast = fast.next.next
            slow = slow.next
            if fast == slow: break
        else:
            return None
                
        new_head = head
        while True:
            if slow == new_head: return slow
            slow = slow.next
            new_head = new_head.next