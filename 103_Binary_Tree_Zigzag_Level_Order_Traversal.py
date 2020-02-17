# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import Queue
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
            
        q = Queue.Queue()
        q.put(root)
        res = []
        cnt = 1
        while not q.empty():
            row = []
            s = q.qsize() 
            for i in range(s):
                t = q.get()
                row.append(t.val)
                if t.left is not None: q.put(t.left)
                if t.right is not None: q.put(t.right)
            if cnt % 2 == 0: row = row[::-1]
            res.append(row)
            cnt += 1

        return res

solution = Solution()
node = TreeNode(1)
node.left = TreeNode(2)
node.right = TreeNode(3)
print solution.zigzagLevelOrder(node)