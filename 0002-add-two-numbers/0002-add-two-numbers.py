# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        temp = ListNode()
        curr = temp
        rem = 0

        while l1!=None or l2!=None:
            val = rem
            if l1!=None:
                val+=l1.val
                l1 = l1.next
            if l2!=None:
                val+=l2.val
                l2 = l2.next
            
            rem = val//10
            val = val%10

            curr.next = ListNode(val)
            curr = curr.next
        
        if rem>0:
            curr.next = ListNode(rem)
        return temp.next
        