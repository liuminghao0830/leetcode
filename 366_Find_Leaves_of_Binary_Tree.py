# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def __init__(self):
        self.res = []

    def dfs(self, root):
        if not root:
            return 0
        level = max(self.dfs(root.left), self.dfs(root.right)) + 1
        
        if len(self.res) < level:
            self.res.append([root.val])
        else:
            self.res[level - 1].append(root.val)

        return level
    def findLeaves(self, root):
        self.dfs(root)
        return self.res
