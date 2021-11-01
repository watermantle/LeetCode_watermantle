# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        arr = []
        while head:
            if not arr: 
                arr.append(head.val)
                head = head.next
            
            if head:
                val = head.val
                idx = bisect.bisect_left(arr, val)
                arr.insert(idx, val)
                head = head.next
            
        dummy_head = tail = ListNode(0)
        while arr:
            top = arr.pop(0)
            tail.next = ListNode(top)
            tail = tail.next
        return dummy_head.next