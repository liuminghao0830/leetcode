class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """

        primes = [True] * n
        cnt = 0

        for i in xrange(2, n):
            if not primes[i]: continue
            cnt += 1
            j = i
            while i * j < n:
                primes[i * j] = False
                j += 1
        return cnt