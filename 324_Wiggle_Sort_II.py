class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # Time: O(Nlog(N))
        # Space: O(N)
        m = (len(nums) + 1) // 2 - 1
        e = len(nums) - 1
        s = sorted(nums)
        for i in range(len(nums)):
            if i % 2:
                nums[i] = s[e]
                e -= 1
            else:
                nums[i] = s[m]
                m -= 1