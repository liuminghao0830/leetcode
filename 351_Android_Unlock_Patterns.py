class Solution(object):
    def numberOfPatterns(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        def dfs(x, remain, skip, vis):
            if remain <= 0:
                return 1

            vis[x] = True
            cnt = 0
            for i in range(1, 10):
                if not vis[i] and (skip[x][i] == 0 or vis[skip[x][i]]):
                    cnt += dfs(i, remain - 1, skip, vis)
            vis[x] = False
            return cnt

        skip = [[0] * 10 for _ in range(10)]
        skip[1][3], skip[3][1] = 2, 2
        skip[4][6], skip[6][4] = 5, 5
        skip[7][9], skip[9][7] = 8, 8
        skip[1][7], skip[7][1] = 4, 4
        skip[2][8], skip[8][2] = 5, 5
        skip[3][9], skip[9][3] = 6, 6
        skip[1][9], skip[9][1] = 5, 5
        skip[3][7], skip[7][3] = 5, 5

        cnt, vis = 0, [False for _ in range(10)]
        for i in range(m, n + 1):
            for s in range(1, 10):
                cnt += dfs(s, i - 1, skip, vis)

        return cnt


solution = Solution()
print(solution.numberOfPatterns(1, 1))
print(solution.numberOfPatterns(1, 2))