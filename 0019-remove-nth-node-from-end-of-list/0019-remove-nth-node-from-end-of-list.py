# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        N, curr = 0, head
        while curr!=None:
            N+=1
            curr = curr.next
        
        n = N-n
        
        if n==0:
            return head.next
        
        curr = head

        while n>1:
            n-=1
            curr = curr.next
        
        curr.next = curr.next.next

        return head
