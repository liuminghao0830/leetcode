class Solution(object):
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        xs = [x for x, y in points]
        min_x, max_x = min(xs), max(xs)
        ym = (min_x + max_x) / 2.
        d = set([tuple(x) for x in points])
        
        for x, y in points:
            coord = tuple([x + 2 * (ym - x), y])
            if coord not in d:
                return False
        
        return True


solution = Solution()
print(solution.isReflected([[1,1],[-1,-1]]))