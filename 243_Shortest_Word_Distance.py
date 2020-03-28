
class Solution(object):
    def shortestDistance(self, words, word1, word2):
        p1 = p2 = -1
        res = len(words)
        for i, word in enumerate(words):
            if word == word1: 
                p1 = i
            elif word == word2: 
                p2 = i
            if p1 >= 0 and p2 >= 0:
                res = min(res, abs(p1 - p2))
        return res