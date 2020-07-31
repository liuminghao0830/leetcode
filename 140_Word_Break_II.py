class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        return self.backtrack(s, wordDict, {})

    def backtrack(self, s, wordDict, memo):
        if not s: return []
        if s in memo: return memo[s]

        res = []
        for word in wordDict:
            if not s.startswith(word):
                continue
            if len(word) == len(s):
                res.append(word)
            else:
                rest = self.backtrack(s[len(word):], wordDict, memo)
                for r in rest:
                    res.append(word + ' ' + r)
        
        memo[s] = res
        return res


solution = Solution()
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
print(solution.wordBreak(s, wordDict))

s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
print(solution.wordBreak(s, wordDict))