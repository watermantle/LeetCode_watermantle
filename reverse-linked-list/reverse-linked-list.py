# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = []
        while head:
            stack.append(head.val)
            head = head.next
        
        dummy_head = tail = ListNode(0)
        
        while stack:
            tail.next = ListNode(stack.pop(-1))
            tail = tail.next
        return dummy_head.next