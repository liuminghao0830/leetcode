# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        # Time: O(n)
        # Space: O(1)
        def dfs(root, v, d, direction):
            if not root and d > 1: return None
            if d > 1:
                root.left = dfs(root.left, v, d - 1, 'left')
                root.right = dfs(root.right, v, d - 1, 'right')
            else:
                t = root
                root = TreeNode(val=v)
                if direction == 'left': root.left = t
                else: root.right = t
            return root
        
        return dfs(root, v, d, 'left')