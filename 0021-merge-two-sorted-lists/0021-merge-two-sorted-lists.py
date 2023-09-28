# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head=ListNode()
        newL=head
        while list1 and list2:
            if list1.val < list2.val:
                newL.next=list1
                list1=list1.next
            else:
                newL.next=list2
                list2=list2.next
            newL=newL.next
        newL.next=list1 or list2 #for when one of them is empty
        return head.next
        