class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        length, cnt, start = 1, 9, 1
        while n > length * cnt:
            n = n - length * cnt
            length = length + 1
            cnt = cnt * 10
            start = start * 10
        num = start + (n - 1) // length
        digit = (n - 1) % length
        return int(str(num)[digit])
        

solution = Solution()
print(solution.findNthDigit(3))
print(solution.findNthDigit(11))
print(solution.findNthDigit(201))