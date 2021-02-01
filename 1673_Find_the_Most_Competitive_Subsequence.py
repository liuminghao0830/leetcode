class Solution(object):
    def mostCompetitive(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Time complexity: O(kn)
        # Space complexity: O(k)
        stack = []
        for i, num in enumerate(nums):
            while stack and stack[-1] > num and len(stack) - 1 + len(nums) - i >= k:
                stack.pop()
            if len(stack) < k:
                stack.append(num)
        return stack

solution = Solution()
print(solution.mostCompetitive([3,5,2,6], 2))