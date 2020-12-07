class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        # Time: O(n)
        # Space: O(n)
        res = [[None] * n for _ in range(n)]
        
        up, down, left, right = 0, n - 1, 0, n - 1
        v = 1
        while up <= down and left <= right and v <= n * n:
            for i in range(left, right + 1):
                res[up][i] = v
                v += 1
            up += 1
            for i in range(up, down + 1):
                res[i][right] = v
                v += 1
            right -= 1
            for i in range(left, right + 1)[::-1]:
                res[down][i] = v
                v += 1
            down -= 1
            for i in range(up, down + 1)[::-1]:
                res[i][left] = v
                v += 1
            left += 1
        return res

solution = Solution()
print(solution.generateMatrix(3))