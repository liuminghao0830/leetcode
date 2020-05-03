class Solution(object):
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        n, m = len(grid), len(grid[0])
        cnt = [[0] * m for _ in range(n)]
        max_kill = 0
        for i in range(n):
            # left -> right
            temp_cnt = 0
            for j in range(m):
                if grid[i][j] == 'E':
                    temp_cnt += 1
                elif grid[i][j] == 'W':
                    temp_cnt = 0
                else:
                    cnt[i][j] += temp_cnt
                    max_kill = max(max_kill, cnt[i][j])
            # right ->left
            temp_cnt = 0
            for j in range(m - 1, -1, -1):
                if grid[i][j] == 'E':
                    temp_cnt += 1
                elif grid[i][j] == 'W':
                    temp_cnt = 0
                else:
                    cnt[i][j] += temp_cnt
                    max_kill = max(max_kill, cnt[i][j])
        for j in range(m):
            # up -> down
            temp_cnt = 0
            for i in range(n):
                if grid[i][j] == 'E':
                    temp_cnt += 1
                elif grid[i][j] == 'W':
                    temp_cnt = 0
                else:
                    cnt[i][j] += temp_cnt
                    max_kill = max(max_kill, cnt[i][j])
            # bottom -> up
            temp_cnt = 0
            for i in range(n - 1, -1, -1):
                if grid[i][j] == 'E':
                    temp_cnt += 1
                elif grid[i][j] == 'W':
                    temp_cnt = 0
                else:
                    cnt[i][j] += temp_cnt
                    max_kill = max(max_kill, cnt[i][j])

        return max_kill



grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
solution =  Solution()
print(solution.maxKilledEnemies(grid))