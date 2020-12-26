class Solution(object):
    def constructArray1(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res = range(1, n + 1)
        for i in range(2, k + 1):
            res[i - 1:] = res[i - 1:][::-1]
        return res

    def constructArray2(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res = []
        i, j = 1, n
        while i <= j:
            if k > 1:
                if k % 2 == 0:
                    res.append(j)
                    j -= 1
                else:
                    res.append(i)
                    i += 1
                k -= 1
            else:
                res.append(i)
                i += 1
        return res
