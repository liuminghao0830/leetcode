"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        # Time: O(n)
        # Space: O(n)
        level = [root]
        while root and level:
            for i in range(1, len(level)):
                level[i - 1].next = level[i]
            level = [s for n in level for s in [n.left, n.right] if s]
        return root

