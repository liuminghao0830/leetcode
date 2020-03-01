class Tree(object):
    def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        v, level = None, [root]
        while root and level:
            v = [x.val for x in level][0]
            temp = [(x.left, x.right) for x in level]
            level = [x for lr in temp for x in lr if x]
        return v
