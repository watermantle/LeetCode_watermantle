# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head: return
        
        fast = slow = head
        
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            
        prev, curr = None, slow
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        p1 = head
        p2 = prev
        
        while p2.next:
            temp = p1.next
            p1.next = p2
            p1 = temp
            
            temp = p2.next
            p2.next = p1
            p2 = temp
        
            