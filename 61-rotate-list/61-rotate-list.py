# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next: return head
        
        
        tail = head
        n = 0
        while tail:
            tail = tail.next
            n += 1
            
        k %= n
        if k == 0: return head
        tail = head
        for _ in range(n - k -1):
            tail = tail.next
        
        temp = tail.next
        tail.next = None
        
        dummy_head = ListNode(0, temp)
        
        for i in range(k - 1):
            temp = temp.next
        temp.next = head
        return dummy_head.next