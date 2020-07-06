class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx, start, end = float('-inf'), -1, -1
        for i, num in enumerate(nums):
            if mx > num:
                if start == -1: start = i - 1
                while start > 0 and nums[start - 1] > num:
                    start -= 1
                end = i + 1
            mx = max(num, mx)
            
        return end - start


nums = [2, 6, 4, 8, 10, 9, 15]
solution = Solution()
print(solution.findUnsortedSubarray(nums))
