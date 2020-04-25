class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        import random
        cnt, res = 0, None
        for i, num in enumerate(self.nums):
            if num == target:
                cnt += 1
                chance = random.randint(1, cnt)
                if chance == cnt:
                    res = i
        return res

nums = [1, 2, 3, 3, 3, 4]
solution = Solution(nums)
print(solution.pick(3))