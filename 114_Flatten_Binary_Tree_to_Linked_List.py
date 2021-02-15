# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if not root:
            return None
        
        left, right = self.flatten(root.left), self.flatten(root.right)
        if not left:
            return root
        
        left_end = left
        while left and left_end.right:
            left_end = left_end.right
        
        root.left = None
        root.right, left_end.right = left, right
        return root