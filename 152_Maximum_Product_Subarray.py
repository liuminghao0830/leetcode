class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pos_memo = [1] * (len(nums) + 1)
        neg_memo = [1] * (len(nums) + 1)
        res = float('-inf')
        for i in range(len(nums)):
            pos_memo[i + 1] = max(max(pos_memo[i] * nums[i], neg_memo[i] * nums[i]), nums[i])
            neg_memo[i + 1] = min(min(pos_memo[i] * nums[i], neg_memo[i] * nums[i]), nums[i])
            res = max(res, pos_memo[i + 1])
        return res