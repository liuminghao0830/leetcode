class Solution(object):
    def get_digit(self, num):
        cnt = 0
        while num > 0:
            cnt += (num % 10)**2
            num /= 10
        return cnt
    
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        pro = set()
        while n not in pro:
            pro.add(n)
            n = sum(int(d)**2 for d in str(n))
            #n = self.get_digit(n)
        return n == 1