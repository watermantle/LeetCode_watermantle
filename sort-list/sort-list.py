# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def merge(l1, l2):
            dummy_head = tail = ListNode(0)
            while l1 and l2:
                if l1.val > l2.val: l1, l2 = l2, l1
                tail.next = l1
                l1 = l1.next
                tail = tail.next
            if l1: tail.next = l1
            if l2: tail.next = l2
            return dummy_head.next
        
        if not head or not head.next: return head
        fast, slow = head.next, head
        
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # midpoint, when stop
        mid = slow.next
        slow.next = None
        return merge(self.sortList(head), self.sortList(mid))
        