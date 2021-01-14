class Solution(object):
    def backtrack(self, i, S):
        if i == len(S):
            return [S]
        if S[i].isdigit():
            return self.backtrack(i + 1, S)
        res = []
        res += self.backtrack(i + 1, S[:i] + S[i].upper() + S[i+1:])
        res += self.backtrack(i + 1, S[:i] + S[i].lower() + S[i+1:])
        return res
        
    def letterCasePermutation1(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        return self.backtrack(0, S)

    def letterCasePermutation2(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        res = [S]
        for i in range(len(S)):
            if S[i].isalpha():
                res.extend([x[:i] + x[i].swapcase() + x[i+1:] for x in res])
        return res


import time
solution = Solution()
s0 = time.time()
print('Method 1:', solution.letterCasePermutation1('a1b2'))
s1 = time.time()
print('{:5f} ms'.format((s1 - s0) * 1000))
print('Method 2:', solution.letterCasePermutation2('a1b2'))
print('{:5f} ms'.format((time.time() - s1) * 1000))