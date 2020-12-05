# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        res, level = [], [root]
        while root and level:
            res += [sum([n.val for n in level]) / (1. * len(level))]
            level = [x for n in level for x in [n.left, n.right] if x]
        return res
        