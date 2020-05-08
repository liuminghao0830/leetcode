# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        parent, queue = {}, [root]
        while root and queue:
            temp = [[t.left, t.right] for t in queue]
            for i, r in enumerate(queue):
                if r.left:
                    parent[r.left.val] = r
                if r.right:
                    parent[r.right.val] = r
            sublevel = [s for n in temp for s in n if s]
            subvals = [s.val for s in sublevel]
            
            if x in subvals and y in subvals and parent[x] != parent[y]:
                return True
            queue = sublevel
        return False