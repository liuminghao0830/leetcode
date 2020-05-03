class Solution(object):
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        nums = [0] * (length + 1)
        for update in updates:
            nums[update[0]] += update[2]
            nums[update[1] + 1] -= update[2]
        
        s = 0
        for i in range(length):
            s += nums[i]
            nums[i] = s
        nums.pop()
        return nums

updates = [[1,3,2],[2,4,3],[0,2,-2]]
solution = Solution()
print(solution.getModifiedArray(5, updates))