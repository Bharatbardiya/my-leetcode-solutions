# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        st1 = set()

        curr1, curr2 = headA, headB
        while curr1!=None:
            st1.add(curr1)
            curr1 = curr1.next
        node = None
        while curr2!=None:
            if curr2 in st1:
                node = curr2
                break
            curr2 = curr2.next
        
        return node
