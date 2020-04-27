import collections

class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if len(s) < k:
            return 0
        
        cnt = collections.Counter(s)
        
        for c, v in cnt.items():
            if v < k:
                return max([self.longestSubstring(x, k) for x in s.split(c)])
        return len(s)


solution = Solution()
print(solution.longestSubstring("aaabb", 3))

print(solution.longestSubstring("ababbc", 2))