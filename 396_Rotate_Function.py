class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if not A:
            return 0
            
        s, n = sum(A), len(A)
        f = [0] * n
        for i, num in enumerate(A):
            f[0] += i * A[i]

        mx = f[0]
        for i in range(1, n):
            f[i] = f[i - 1] + s - n * A[n - i]
            mx = max(mx, f[i])
        return mx

solution = Solution()
print(solution.maxRotateFunction([4, 3, 2, 6]))