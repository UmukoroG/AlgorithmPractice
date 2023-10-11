# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        p_arr=[]
        q_arr=[]

        def helper(node, arr):
            if node==None:
                arr.append(None)
            elif node != None:
                arr.append(node.val)
                helper(node.left,arr)
                helper(node.right,arr)
        helper(p, p_arr)
        helper(q, q_arr)

        return p_arr == q_arr