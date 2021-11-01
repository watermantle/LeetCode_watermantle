# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = tail = ListNode(0)
        while(l1 and l2):
            if l1.val > l2.val:
                l1, l2 = l2, l1
            tail.next = l1
            tail = tail.next
            l1 = l1.next
        
        if l1: tail.next = l1
        if l2: tail.next = l2
        return dummy_head.next