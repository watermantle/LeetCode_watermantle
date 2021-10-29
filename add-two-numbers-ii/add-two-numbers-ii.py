# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        stack1, stack2 = [], []
        while l1: 
            stack1.append(l1.val)
            l1 = l1.next
        while l2:
            stack2.append(l2.val)
            l2 = l2.next
        
        dummy_head = tail= ListNode()
        carry = 0
        res = []
        while stack1 or stack2 or carry:
            sum_ = (stack1.pop() if stack1 else 0) + (stack2.pop() if stack2 else 0) + carry
            carry = sum_ // 10
            res.append(sum_ % 10)
        
        for val in res[::-1]:
            tail.next = ListNode(val)
            tail = tail.next
        return dummy_head.next