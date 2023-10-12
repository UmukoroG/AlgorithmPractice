# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        res=[]       
        if not root:
            return 

        queue=[] 
        queue.append(root)

        while queue:
            level=[]
            levelSize=len(queue)
            
            for _ in range(levelSize):
                curr_node=queue.pop(0)
                level.append(curr_node.val)

                if curr_node.left:
                    queue.append(curr_node.left)
                if curr_node.right:
                    queue.append(curr_node.right)
            res.append(level)
            
        return res
        
        

        