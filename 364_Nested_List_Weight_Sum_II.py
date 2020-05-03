
class Solution(object):
    def __init__(self):
        self.cnt = []
        self.level = 0

    def dfs(self, nestedList, level):
        for nl in nestedList:
            if not nl.isInteger():
                self.dfs(nl.getList(), level + 1)
            else:
                self.cnt.append([level, nl.getInteger()])

        self.level = max(level, self.level)

            
    def depthSumInverse(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        self.dfs(nestedList, 1)
        s = 0
        for c in self.cnt:
            s += (self.level - c[0] + 1) * c[1]
        return s
