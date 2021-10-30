# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy_head = tail = ListNode()
        
        pq = PriorityQueue()
        # dummy number to avoid ListNode comparison
        dummy_num = 0
        for head in lists:
            if head:
                pq.put((head.val, dummy_num, head))
                dummy_num += 1
        
        while not pq.empty():
            _, _, top = pq.get()
            if top.next:
                pq.put((top.next.val, dummy_num, top.next))
                dummy_num += 1
            tail.next = top
            tail = tail.next
        return dummy_head.next
