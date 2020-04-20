# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # dfs time complexity O(n), n: # of nodes
    def dfs(self, nums):
        if not nums:
            return None
        root = TreeNode(nums[0])
        
        mid = next((i for i, val in enumerate(nums) if val > root.val), len(nums))
        root.left = self.dfs(nums[1:mid])
        root.right = self.dfs(nums[mid:])
        return root
        
    def bstFromPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: TreeNode
        """
        root = self.dfs(preorder)
        return root
