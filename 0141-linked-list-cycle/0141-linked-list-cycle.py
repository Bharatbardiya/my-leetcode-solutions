# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head==None or head.next==None:
            return False
        
        slow, fast = head, head
        
        slow = slow.next
        fast = fast.next.next

        while fast!=None and fast.next!=None:
            if slow==fast:
                return True
            slow = slow.next
            fast = fast.next.next
        
        return False
        