# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummyNode=ListNode(0, head)
        l=dummyNode
        r=head

        while n>0 and r:
            r=r.next
            n-=1
        
        while r:
            l=l.next
            r=r.next
        l.next=l.next.next #Delete the mth node 

        #dummy node contains a node, the pos before head so we return the next node which is the head
        return dummyNode.next



        