class Solution(object):
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        nums = [a*x*x + b*x + c for x in nums]
        if a < 0:
            nums = [-x for x in nums]
        left, right = 0,  len(nums) - 1
        res = [0] * len(nums)
        i = 0
        while left <= right:
            if nums[left] > nums[right]:
                res[i] = nums[left]
                left += 1
            else:
                res[i] = nums[right]
                right -= 1
            i += 1
        if a < 0:
            res = [-x for x in res]
        return res[::-1] if a >= 0 else res


solution = Solution()
nums = [-4, -2, 2, 4]
print(solution.sortTransformedArray(nums, 1, 3, 5))
print(solution.sortTransformedArray(nums, -1, 3, 5))
