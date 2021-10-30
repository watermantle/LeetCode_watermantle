# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # fast&slow pointers
        fast, slow = head, head
        while fast:
            if not fast.next: return False
            fast = fast.next.next
            slow = slow.next
            if slow == fast: return True
        return False