class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def backtrack(nums, t, seen):
            if t in seen: return seen[t]
            if t == 0:
                seen[t] = True
                return True

            seen[t] = False
            for i in range(len(nums)):
                if t - nums[i] >= 0:
                    seen[t] = seen[t] | backtrack(nums[i+1:], t - nums[i], seen)
                    if seen[t]:
                        return True
            return seen[t]

        s = sum(nums)
        if s % 2: return False
        return backtrack(nums, s // 2, {})

s = Solution()
print(s.canPartition([1,5,11,5]))
print(s.canPartition([1,2,3,5]))