# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy_head = ListNode()
        dummy_head.next = head
        # head & dummy_head point to the first item
        head = dummy_head
        
        while head.next and head.next.next:
            n1, n2 = head.next, head.next.next
            # n1 connects to what n2 connects
            n1.next = n2.next
            # n2 connects to n2
            n2.next = n1
            # head connects to n2
            head.next = n2
            
            # head jumps over two nodes
            head = n1
        return dummy_head.next