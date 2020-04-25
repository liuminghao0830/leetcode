class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        res = self.nums[:]
        for i in range(len(self.nums)):
            j = random.randrange(0, i + 1)
            res[i], res[j] = res[j], res[i]
        return res