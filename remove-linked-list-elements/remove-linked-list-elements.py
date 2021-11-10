# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = tail = ListNode(None, head)
        while head:
            if head.val == val:
                tail.next = head.next
                head = head.next
            else:
                tail = head
                head = head.next
        return dummy.next