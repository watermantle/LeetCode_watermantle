# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        fast, slow = head, head
        while fast:
            if not fast.next: return None
            fast = fast.next.next
            slow = slow.next
            if fast == slow: break
        else:
            return None
        
        new = head
        while True:
            if slow == new: return slow
            slow = slow.next
            new = new.next