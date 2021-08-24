# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        temp = head
        
        while temp and temp.next:
            temp.val, temp.next.val = temp.next.val, temp.val
            temp = temp.next.next
        
        return head