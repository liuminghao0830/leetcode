# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        def dfs(node):
            if not node: return ''
            if node.left is None and node.right:
                return '(' + str(node.val) + '()' + dfs(node.right) + ')'
            return '(' + str(node.val) + dfs(node.left) + dfs(node.right) + ')'
        return dfs(t)[1:-1]