import collections

class Solution(object):
    def longestSubstring_divide_conq(self, s, k):
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

    def longestSubstring_sliding_window(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 0
        maxUniq = len(set(s))

        for n_uniq in range(1, maxUniq + 1):
            cnt = collections.Counter()
            uniq, cntAtleastK = 0, 0
            win_start, win_end = 0, 0
            while win_end < len(s):
                if uniq <= n_uniq:
                    if cnt[s[win_end]] == 0:
                        uniq += 1
                    cnt[s[win_end]] += 1
                    if cnt[s[win_end]] == k:
                        cntAtleastK += 1
                    win_end += 1
                else:
                    if cnt[s[win_start]] == k:
                        cntAtleastK -= 1
                    cnt[s[win_start]] -= 1
                    if cnt[s[win_start]] == 0:
                        uniq -= 1
                    win_start += 1
                if uniq == n_uniq and cntAtleastK == n_uniq:
                    res = max(res, win_end - win_start)

        return res


solution = Solution()
print(solution.longestSubstring_sliding_window("aaabb", 3))

print(solution.longestSubstring_sliding_window("ababbc", 2))