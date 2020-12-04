class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        # time complexity: O(log(n))
        # space complexity: O(1)
        if n == 1: return 0
        
        for i in range(2, n):
            if n % i == 0:
                return i + self.minSteps(n / i)
        return n


solution = Solution()
print(solution.minSteps(5))
print(solution.minSteps(10))