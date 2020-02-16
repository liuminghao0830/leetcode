class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # O(n) : 80%
        num = "123456789"
        res = ""
        fn = [1]*n
        for i in range(1, n):
            fn[i] = fn[i - 1] * i
        k = k - 1

        for i in range(1, n + 1):
            j = k // fn[n - i]
            k = k % fn[n - i]
            res = res + num[j]
            num = num[:j] + num[j + 1:]
        return res

solution = Solution()
print solution.getPermutation(3, 3)