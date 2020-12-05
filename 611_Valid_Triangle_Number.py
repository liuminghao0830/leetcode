class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Time: O(N^2log(N))
        # Space: O(1)
        if len(nums) < 3: return 0

        nums.sort()

        cnt = 0
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                l, k = j + 1, len(nums)
                while l < k:
                    m = l + (k - l) // 2
                    if nums[m] < nums[i] + nums[j]:
                        l = m + 1
                    else:
                        k = m
                cnt += k - j - 1
        return cnt

    def triangleNumber2(self, nums):
        # Time: O(N^2)
        # Space: O(1)
        nums.sort()
        cnt = 0
        for k in range(2, len(nums))[::-1]:
            i, j = 0, k - 1
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    cnt += j - i
                    j -= 1
                else:
                    i += 1
        return cnt


solution = Solution()
print(solution.triangleNumber2([2,2,3,4]))