# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        size = 0
        new_head = head
        while new_head:
            size += 1
            new_head = new_head.next
        
        if n == size: return head.next
        
        dummy = head
        for i in range(size - n - 1):
            dummy = dummy.next
        dummy.next = dummy.next.next
        return head