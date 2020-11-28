import collections

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # use deque as stack + queue
        d = collections.deque()
        res = []
        for i, n in enumerate(nums):
            # maintain a max stack
            while d and nums[d[-1]] < n:
                d.pop()
            d.append(i)
            # maintain stack/queue with size <= k
            if i - d[0] >= k: d.popleft()
            # start sliding: store max num in queue
            if i >= k - 1: res.append(nums[d[0]])
            
        return res


solution = Solution()
print(solution.maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))