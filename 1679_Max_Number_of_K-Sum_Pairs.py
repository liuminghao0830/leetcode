class Solution(object):
    def maxOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # time complexity: O(n)
        # space complexity: O(n)
        import collections

        vis = collections.defaultdict(int)
        cnt = 0
        for num in nums:
            if vis[k - num] > 0:
                cnt += 1
                vis[k - num] -= 1
            else:
                vis[num] += 1
        return cnt


solution = Solution()
print(solution.maxOperations([1,2,3,4], 5))
print(solution.maxOperations([3,1,3,4,3], 6))