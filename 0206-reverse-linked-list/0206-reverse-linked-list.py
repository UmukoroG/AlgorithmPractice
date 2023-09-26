# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev= None
        curr=head
        while curr:
            tempNode=curr.next
            curr.next=prev #this is where the links are broken to be reversed
            prev=curr
            curr=tempNode

        return prev